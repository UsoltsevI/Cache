//------------------------------------------------------------------------------
//
// Cache LRU-K implementation
// 
//------------------------------------------------------------------------------
//
// This file implements a different algorithm from the 
// classical one for processing cases when less than K 
// elements are stored in the page histories.
//
// If a page has less than K elements stored in the page 
// history, then we simply look at its last recorded 
// element as the kth, sorting in the tree by its value.
//
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"
#include "../include/queue.h"
#include "../include/hash.h"
#include "../include/tree.h"

struct history {
    TQueue* queue;
    TCachePage page;
    TCacheKey  itr;
};

struct cache {
    THist* histories;
    TMap*  table;
    rbtree tree;
    size_t cur_lst;
    size_t size;
    size_t k;
    size_t iteration;
};

int compare_hist_itr(void* first, void* second) {
    return *((size_t*) first) - *((size_t*) second);
}

TCache* create_cache(size_t size, size_t k) {
    TCache* cch = (TCache*) calloc(1, sizeof(TCache));

    cch->size = size;
    cch->k    = k;

    cch->table = create_table(cch->size);
    cch->tree  = rbtree_create(cch->size);

    cch->histories = (THist*) calloc(cch->size, sizeof(THist));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->histories[i].queue = create_queue(cch->k);
    }

    cch->cur_lst = 0;
    cch->iteration = 0;

    return cch;
}

int cache_update(TCache* cch
            , int key
            , TCachePage (*get_page) (int)) {

    ++(cch->iteration);

    THist* hst = table_search_cell(cch->table, key);
    
    // hit
    if (hst != NULL) {
        rbtree_delete(cch->tree, hst->itr, &compare_hist_itr);

        queue_add_to_head(hst->queue, cch->iteration);

        hst->itr = queue_get_tail(hst->queue);

        rbtree_insert(cch->tree, hst->itr, hst, &compare_hist_itr);

        return 1;
    }

    // miss
    if (cch->cur_lst == cch->size) {
        hst = tree_delete_min(cch->tree, &compare_hist_itr);

        table_delete_cell(cch->table, hst->page);
        queue_clean(hst->queue);

#ifdef CACHE_DEBUGON
        printf("del->time = %lu\n", hst->itr);
#endif

        hst->page = get_page(key);
        hst->itr  = cch->iteration;

        table_add_value(cch->table, hst, key);
        queue_add_to_head(hst->queue, hst->itr);
        rbtree_insert(cch->tree, hst->itr, hst, &compare_hist_itr);

    } else {
        hst = &cch->histories[cch->cur_lst];

        hst->page = get_page(key);
        hst->itr  = cch->iteration;

        table_add_value(cch->table, hst, key);
        rbtree_insert(cch->tree, hst->itr, hst, &compare_hist_itr);
        queue_add_to_head(hst->queue, cch->iteration);

        cch->cur_lst += 1;
    }

    return 0;
}

void delete_cache(TCache* cch) {
    delete_table(cch->table);
    rbtree_clean(cch->tree);

    for (size_t i = 0; i < cch->size; ++i) {
        queue_delete(cch->histories[i].queue);
    }

    free(cch->histories);
    free(cch);
}

#ifdef CACHE_DEBUGON
    void hist_dump(THist* hist) {
        printf("hist->page = %lu\n", hist->page);
        printf("hist->time = %lu\n", hist->time);
        printf("hist->list = %p \n", hist->list);
        list_dump(hist->list);
    }

    void cache_dump(TCache* cch) {
        printf("Table:\n");
        print_hash_table(cch->table);

        printf("Lists:\n");
        for (size_t i = 0; i < cch->size; ++i) {
            hist_dump(&cch->histories[i]);
        }

        printf("Tree:\n");
        // draw_tree(cch->tree);
        rbtree_dump(cch->tree);
        printf("\n\n");
    }

    TCacheTime hist_get_time(THist* hist) {
        return hist->time;
    }
#endif
