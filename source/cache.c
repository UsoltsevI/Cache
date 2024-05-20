//------------------------------------------------------------------------------
//
// Cache LRU-K implementation
//
//------------------------------------------------------------------------------
//
// This file implements the classic LRU-K algorithm described in the 
// following article:
// https://github.com/UsoltsevI/Cache/blob/main/documents/Eng_LRU_K.pdf
// 
// It uses a tree to find the element whose kth access was the earliest.
// A list separate from the tree is used to find the earliest element 
// if there are pages with less than K hits stored in the directory.
//
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/cache.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/tree.h"
#include "../include/queue.h"

struct cache {
    THist* histories;
    TList* list;
    TMap*  table;
    rbtree tree;
    size_t size;
    size_t k;
    size_t iteration;
    size_t cur_hst;
};

struct history {
    TNode* node;
    TQueue* queue;
    TCachePage page;
    TCacheKey  key;
    size_t  last_itr;
};

static const size_t MINUS_INF = 0;

int compare_hist_itr(void* first, void* second) {
    return *((size_t*) first) -  *((size_t*) second);
}

TCache* create_cache(size_t size, size_t k) {
    TCache* cch = (TCache*) calloc(1, sizeof(TCache));

    cch->size = size;
    cch->k    = k;

    cch->table = create_table(cch->size);
    cch->tree  = rbtree_create(cch->size);
    cch->list  = create_list(cch->size + 1);

    cch->histories = (THist*) calloc(cch->size, sizeof(THist));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->histories[i].queue = create_queue(cch->k);
    }

    cch->cur_hst = 0;
    cch->iteration = 0;

    return cch;
}

#ifdef CACHE_DEBUGON
    void print_cache_opened_pages(TCache* cch) {
        printf("OPENED PAGES: ");
        for (size_t i = 0; i < cch->cur_hst; i++) {
            printf("%ld ", cch->histories[i].key);
        }

        printf("\n");
    }
#endif

int cache_update(TCache* cch
            , int key
            , TCachePage (*get_page) (int)) {

    ++(cch->iteration);

    THist* hst = table_search_cell(cch->table, key);

#ifdef CACHE_DEBUGON
    print_cache_opened_pages(cch);
    printf("new key: %d\n", key);
    list_dump(cch->list);
    printf("\033[96m verify in cache:\n");
    list_verificator(cch->list);
    printf("verifyed \033[97m \n");
    if (cch->iteration > 2) {
        // draw_tree(cch->tree);
    }
#endif

    if (hst != NULL) {
        if (hst->last_itr == MINUS_INF) {
        #ifdef CACHE_DEBUGON
            printf("hit from list\n");
        #endif

            queue_add_to_head(hst->queue, cch->iteration);

            hst->last_itr = queue_get_tail(hst->queue);

            if (hst->last_itr != MINUS_INF) {
                assert(hst->node != NULL);

                list_delete_node(cch->list, hst->node);
                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);

            #ifndef NDEBUG
                hst->node = NULL;
            #endif
                assert(hst->node == NULL);

            } else {
                assert(hst->node != NULL);
                list_delete_node(cch->list, hst->node);
                list_add_to_head(cch->list, hst);
                hst->node = list_get_head(cch->list);
            }

        } else {
        #ifdef CACHE_DEBUGON
            printf("hit from tree\n");
        #endif

            rbtree_delete(cch->tree, hst->last_itr, &compare_hist_itr);


            queue_add_to_head(hst->queue, cch->iteration);

            hst->last_itr = queue_get_tail(hst->queue);

            assert(hst->last_itr != MINUS_INF);
            assert(hst->node == NULL);

            rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
        }

    #ifdef CACHE_DEBUGON
        printf("\n");
    #endif

        return 1;
    }

    if (cch->cur_hst == cch->size) {
    #ifdef CACHE_DEBUGON
        printf("replace old\n");
    #endif

        if (list_get_head(cch->list) != NULL) {
        #ifdef CACHE_DEBUGON
            printf("from list\n");
        #endif

            hst = list_get_value(list_get_tail(cch->list));
        #ifdef CACHE_DEBUGON
            printf("hst->node = %p\n", hst->node);
            printf("hst->key  = %p\n", hst->key );
        #endif

            assert(hst->node != NULL);
            assert(hst->last_itr == MINUS_INF);

            table_delete_cell(cch->table, hst->key);

            queue_clean(hst->queue);

            queue_add_to_head(hst->queue, MINUS_INF);
            queue_add_to_head(hst->queue, cch->iteration);

            hst->key = key;
            hst->page = get_page(key);
            hst->last_itr = queue_get_tail(hst->queue);

            table_add_value(cch->table, hst, key);

            if (hst->last_itr == MINUS_INF) {
                assert(hst->node != NULL);
                list_delete_node(cch->list, hst->node);
                list_add_to_head(cch->list, hst);
                hst->node = list_get_head(cch->list);

            } else {
                assert(hst->node != NULL);
                list_delete_node(cch->list, hst->node);

                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
            
            #ifndef NDEBUG
                hst->node = NULL;
            #endif
                assert(hst->node == NULL);

            }

        } else {
        #ifdef CACHE_DEBUGON
            printf("from tree\n");
        #endif

            hst = tree_delete_min(cch->tree, &compare_hist_itr);

            assert(hst->node == NULL);
            assert(hst->last_itr != MINUS_INF);

            table_delete_cell(cch->table, hst->key);

            queue_clean(hst->queue);

            queue_add_to_head(hst->queue, MINUS_INF);
            queue_add_to_head(hst->queue, cch->iteration);

            hst->key = key;
            hst->page = get_page(key);
            hst->last_itr = queue_get_tail(hst->queue);

            table_add_value(cch->table, hst, key);

            if (hst->last_itr == MINUS_INF) {
                list_add_to_head(cch->list, hst);
                hst->node = list_get_head(cch->list);
                assert(hst->node != NULL);

            } else {
                assert(hst->node == NULL);
                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
                #ifndef NDEBUG
                    hst->node = NULL;
                #endif
                assert(hst->node == NULL);
            }
        }

    } else {
    #ifdef CACHE_DEBUGON
        printf("from accumulator\n");
    #endif

        hst = &cch->histories[cch->cur_hst];

        cch->cur_hst += 1;

        hst->key  = key;
        hst->page = get_page(key);

        queue_add_to_head(hst->queue, MINUS_INF);
        queue_add_to_head(hst->queue, cch->iteration);

        hst->last_itr = queue_get_tail(hst->queue);
        
        table_add_value(cch->table, hst, key);
        
        if (hst->last_itr == MINUS_INF) {
        #ifdef CACHE_DEBUGON
            printf("to list\n");
        #endif

            list_add_to_head(cch->list, hst);
            hst->node = list_get_head(cch->list);
            assert(hst->node != NULL);

        #ifdef CACHE_DEBUGON
            printf("hst->node = %p\n", hst->node);
        #endif

        } else {
        #ifdef CACHE_DEBUGON
            printf("to tree\n");
        #endif

            rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);

            #ifndef NDEBUG
                hst->node = NULL;
            #endif
            assert(hst->node == NULL);
        }
    }

#ifdef CACHE_DEBUGON
    printf("\n");
#endif

    return 0;
}

void delete_cache(TCache* cch) {
    delete_table(cch->table);
    rbtree_clean(cch->tree);
    delete_list(cch->list);

    for (size_t i = 0; i < cch->size; ++i) {
        queue_delete(cch->histories[i].queue);
    }

    free(cch->histories);
    free(cch);
}

#ifdef CACHE_DEBUGON
    TCacheKey hist_get_key(THist* hist) {
        return hist->key;
    }

    size_t hist_get_last_itr(THist* hist) {
        return hist->last_itr;
    }
#endif
