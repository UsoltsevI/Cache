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

    // we are looking among the open pages
    THist* hst = table_search_cell(cch->table, key);
    
    if (hst != NULL) { // hit!
        // if the lst is found, then we update 
        // the information in the cch->list and in the cch->tree

        // deleting the cell from the cch->tree
        rbtree_delete(cch->tree, hst->itr, &compare_hist_itr);

        // adding the new page to the head of the list
        queue_add_to_head(hst->queue, cch->iteration);

        // updating the hst->time value
        hst->itr = queue_get_tail(hst->queue);

        // adding the new tail to the ссh->tree
        rbtree_insert(cch->tree, hst->itr, hst, &compare_hist_itr);

        return 1;
    }

    // miss
    // if the page was not opened
    // we are checking if we still have free slots for the page
    if (cch->cur_lst == cch->size) {
        // if there are no free ones left, 
        // then we remove the minimum value from the cch->tree,
        // and in its place we will write the next value
        hst = tree_delete_min(cch->tree, &compare_hist_itr);

#ifdef CACHE_DEBUGON
        printf("del->time = %lu\n", hst->itr);
#endif
        // deleting the list from the cch->table
        table_delete_cell(cch->table, hst->page);

#ifdef CACHE_PAGE_LINKS_ON
        // writing down the value of the closed page
        *to_close = hst->page
#endif

        // deleting elements from list
        queue_clean(hst->queue);

        hst->page = get_page(key);
        hst->itr  = cch->iteration;

        table_add_value(cch->table, hst, key);
        queue_add_to_head(hst->queue, hst->itr);
        rbtree_insert(cch->tree, hst->itr, hst, &compare_hist_itr);

    } else {
        // if there are still free lists left, 
        // just write them down there
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
