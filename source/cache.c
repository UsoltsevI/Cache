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
    return *((size_t*) first) - *((size_t*) second);
}

TCache* create_cache(size_t size, size_t k) {
    TCache* cch = (TCache*) calloc(1, sizeof(TCache));

    cch->size = size;
    cch->k    = k;

    cch->table = create_table(cch->size);
    cch->tree  = rbtree_create(cch->size);
    cch->list  = create_list(cch->size);

    cch->histories = (THist*) calloc(cch->size, sizeof(THist));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->histories[i].queue = create_queue(cch->k);
    }

    cch->cur_hst = 0;
    cch->iteration = 0;

    return cch;
}

int cache_update(TCache* cch
            , int key
            , TCachePage (*get_page) (int)) {

    ++(cch->iteration);

    THist* hst = table_search_cell(cch->table, key);

    if (hst != NULL) {
        if (hst->last_itr == MINUS_INF) {
            queue_add_to_head(hst->queue, cch->iteration);

            hst->last_itr = queue_get_tail(hst->queue);

            if (hst->last_itr != MINUS_INF) {
                list_delete_node(cch->list, hst->node);
                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);

                #ifdef DEBUGON
                    hst->node = NULL;
                #endif

            } else {
                list_move_to_head(cch->list, hst->node);
            }

        } else {
            rbtree_delete(cch->tree, hst->last_itr, &compare_hist_itr);

            queue_add_to_head(hst->queue, cch->iteration);

            hst->last_itr = queue_get_tail(hst->queue);

            assert(hst->last_itr != MINUS_INF);
            assert(hst->node == NULL);

            rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
        }

        return 1;
    }

    if (cch->cur_hst == cch->size) {
        if (list_get_head(cch->list) == NULL) {
            hst = list_get_value(list_get_tail(cch->list));

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
                list_move_to_head(cch->list, hst->node);

            } else {
                list_delete_node(cch->list, hst->node);
                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
            
                #ifdef DEBUGON
                    hst->node = NULL;
                #endif
            }

        } else {
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

            } else {
                rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);
            }
        }

    } else {
        hst = &cch->histories[cch->cur_hst];

        cch->cur_hst += 1;

        hst->key  = key;
        hst->page = get_page(key);

        queue_add_to_head(hst->queue, MINUS_INF);
        queue_add_to_head(hst->queue, cch->iteration);

        hst->last_itr = queue_get_tail(hst->queue);
        
        table_add_value(cch->table, hst, key);
        
        if (hst->last_itr == MINUS_INF) {
            list_add_to_head(cch->list, hst);
            hst->node = list_get_head(cch->list);

        } else {
            rbtree_insert(cch->tree, hst->last_itr, hst, &compare_hist_itr);

            #ifdef DEBUGON
                hst->node = NULL;
            #endif
        }
    }

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
