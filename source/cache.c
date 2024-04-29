#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/tree.h"

struct _history {
    List* list;
    TCacheValue page;
};

typedef struct cache {
    THist* histories;
    TMap* table;
    rbtree tree;
    size_t cur_lst;
    size_t size;
    size_t k;
} Cache;

Cache* create_cache(size_t size, size_t k) {
    Cache* cch = (Cache*) calloc(1, sizeof(Cache));

    cch->size = size;
    cch->k = k;

    cch->table = create_table(cch->size);
    //cch->tree  = create_tree (cch->size);
    cch->tree = rbtree_create();
    cch->histories = (THist*) calloc(cch->size, sizeof(THist));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->histories[i].list = create_list(cch->k);
    }

    cch->cur_lst = 0;

    return cch;
}

int cache(struct cache* cch
            , const TCacheValue* page
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
    THist* hst = table_search_cell(cch->table, *page);
    
    // if the lst is found, then we update 
    // the information in the cch->list and in the cch->tree
    if (hst != NULL) {
        // hit!
        // deleting the cell from the cch->tree
        TCacheTime temp = list_get_value(list_get_tail(hst->list));
        //tree_delete_node(cch->tree, t);
        rbtree_delete(cch->tree, &temp, &compare_time);

        // adding the new page to the head of the list
        list_add_to_head(hst->list, time);
        // adding the new tail to the ссh->tree
        temp = list_get_value(list_get_tail(hst->list));
        //tree_add_value(cch->tree, hst->list, t);
        rbtree_insert (cch->tree, hst, &temp, &compare_time);

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
        THist* del = tree_delete_min(cch->tree);
        // deleting the list from the cch->table
        table_delete_cell(cch->table, del->page);

#ifdef CACHE_PAGE_LINKS_ON
        // writing down the value of the closed page
        *to_close = del->page
#endif

        // deleting elements from list
        list_clean(del->list);
        del->page = *page;
        table_add_value(cch->table, del, *page);
        list_add_to_head(del->list, time);
        //tree_add_value(cch->tree, del, time);
        rbtree_insert (cch->tree, del, &time, &compare_time);

    } else {
        // if there are still free lists left, 
        // just write them down there
        cch->histories[cch->cur_lst].page = *page;
        table_add_value(cch->table, &cch->histories[cch->cur_lst], *page);
        //tree_add_value (cch->tree, cch->histories[cch->cur_lst], time);
        rbtree_insert (cch->tree, &cch->histories[cch->cur_lst], &time, &compare_time);
        cch->cur_lst += 1;

#ifdef CACHE_PAGE_LINKS_ON
        *to_close = NULL;
#endif
    }

    return 0;
}

void delete_cache(Cache* cch) {
    delete_table(cch->table);
    delete_tree (cch->tree);

    for (size_t i = 0; i < cch->size; ++i) {
        delete_list(cch->histories[i].list);
    }

    free(cch->histories);
    free(cch);
}
