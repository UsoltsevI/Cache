#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/tree.h"

struct history {
    TList* list;
    TCacheValue page;
    TCacheTime time;
};

struct cache {
    THist* histories;
    TMap* table;
    rbtree tree;
    size_t cur_lst;
    size_t size;
    size_t k;
};

int compare_hist_time(void* first, void* second) {
    THist* first_struct  = (THist*) first;
    THist* second_struct = (THist*) second;

    if (first_struct->time < second_struct->time) {
        return -1;

    } else if (first_struct->time < second_struct->time) {
        return 1;
    }

    return 0;
}

TCache* create_cache(size_t size, size_t k) {
    TCache* cch = (TCache*) calloc(1, sizeof(TCache));

    cch->size = size;
    cch->k    = k;

    cch->table = create_table(cch->size);
    cch->tree  = rbtree_create();

    cch->histories = (THist*) calloc(cch->size, sizeof(THist));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->histories[i].list = create_list(cch->k);
    }

    cch->cur_lst = 0;

    return cch;
}

int cache(TCache* cch
            , const TCacheValue page
            , TCacheTime time
#ifdef CACHE_PAGE_LINKS_ON
            , TCacheValue* to_close
#endif
            ) {

#ifdef CACHE_PAGE_LINKS_ON
    if (page == NULL || to_close == NULL) {
        fprintf(stderr, "NULL argument in the file %s"
                        ", in the function %s"
                        ", on the line %d\n", __FILE__
                        , __func__, __LINE__);
        return 0;
    }
#endif

    // we are looking among the open pages
    THist* hst = table_search_cell(cch->table, page);
    
    // if the lst is found, then we update 
    // the information in the cch->list and in the cch->tree
    if (hst != NULL) {
        // hit!
        // deleting the cell from the cch->tree
        rbtree_delete(cch->tree, hst, &compare_hist_time);
        // adding the new page to the head of the list
        list_add_to_head(hst->list, time);
        // adding the new tail to the ссh->tree
        hst->time = list_get_value(list_get_tail(hst->list));
        rbtree_insert(cch->tree, hst, &compare_hist_time);

#ifdef CACHE_PAGE_LINKS_ON
        // there is no need to close anything
        *to_close = NULL;
#endif
        return 1;
    }

    // miss
    // if the page was not opened
    // we are checking if we still have free slots for the page
    if (cch->cur_lst == cch->size) {
        // if there are no free ones left, 
        // then we remove the minimum value from the cch->tree,
        // and in its place we will write the next value
        THist* del = tree_delete_min(cch->tree, &compare_hist_time);
        // deleting the list from the cch->table
        table_delete_cell(cch->table, del->page);

#ifdef CACHE_PAGE_LINKS_ON
        // writing down the value of the closed page
        *to_close = del->page
#endif

        // deleting elements from list
        list_clean(del->list);

        del->page = page;
        del->time = time;

        table_add_value(cch->table, del, page);
        list_add_to_head(del->list, del->time);
        rbtree_insert(cch->tree, del, &compare_hist_time);

    } else {
        // if there are still free lists left, 
        // just write them down there
        cch->histories[cch->cur_lst].page = page;
        cch->histories[cch->cur_lst].time = time;

        table_add_value(cch->table, &cch->histories[cch->cur_lst], page);
        rbtree_insert(cch->tree, &cch->histories[cch->cur_lst], &compare_hist_time);
        list_add_to_head(cch->histories[cch->cur_lst].list, time);

        cch->cur_lst += 1;

#ifdef CACHE_PAGE_LINKS_ON
        *to_close = NULL;
#endif
    }

    return 0;
}

void delete_cache(TCache* cch) {
    delete_table(cch->table);
    rbtree_clean(cch->tree);

    for (size_t i = 0; i < cch->size; ++i) {
        delete_list(cch->histories[i].list);
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

    printf("\n");
}
#endif
