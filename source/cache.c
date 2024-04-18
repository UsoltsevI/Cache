#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/tree.h"

typedef struct cache {
    List** lists;
    TMap* table;
    TTree* tree;
    size_t cur_lst;
    size_t size;
    size_t k;
} Cache;

Cache* create_cache(size_t size, size_t k) {
    Cache* cch = (Cache*) calloc(1, sizeof(Cache));

    cch->size = size;
    cch->k = k;

    cch->table = create_table(cch->size);
    cch->tree  = create_tree (cch->size);
    cch->lists = (List**) calloc(cch->size, sizeof(List*));

    for (size_t i = 0; i < cch->size; ++i) {
        cch->lists[i] = create_list(cch->k);
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
        fprintf(stderr, "NULL argument in the file %s
                        , in the function %s
                        , on the line %d\n", __FILE__
                        , __func__, __LINE__);
        return 0;
    }
#endif

    // we are looking among the open pages
    List* lst = table_search_cell(cch->table, page);
    
    // if the lst is found, then we update 
    // the information in the cch->list and in the cch->tree
    if (lst != NULL) {
        // hit!
        // deleting the cell from the cch->tree
        tree_delete_node(cch->tree, list_get_value(list_get_tail(lst)));
        // adding the new page to the head of the list
        list_add_to_head(lst, time);
        // adding the new tail to the ссh->tree
        tree_add_value(cch->tree, lst, list_get_value(list_get_tail(lst)));

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
        List* del = tree_delete_min(cch->tree);
        // deleting the list from the cch->table
        table_delete_cell(del, list_get_main_value(del));

#ifdef CACHE_PAGE_LINKS_ON
        // writing down the value of the closed page
        *to_close = list_get_main_value(del);
#endif

        // deleting elements from list
        list_clean(del);
        list_set_main_value(del, page);
        table_add_value(cch->table, del, page);
        list_add_to_head(del, time);
        tree_add_value(cch->tree, del, time);

    } else {
        // if there are still free lists left, 
        // just write them down there
        list_set_main_value(cch->lists[cch->cur_lst], page);
        table_add_value(cch->table, cch->lists[cch->cur_lst], page);
        tree_add_value (cch->tree, cch->lists[cch->cur_lst], time);
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
        delete_list(cch->lists[i]);
    }

    free(cch->lists);
    free(cch);
}
