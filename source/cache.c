#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/tree.h"

typedef size_t TCacheValue;
typedef struct cache {
    List** lists;
    TMap* table;
    TTree* tree;
    size_t cur_lst;
    size_t size;
    size_t k;
} Cache;

struct cache* create_cache(size_t size, size_t k) {
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
    if (page == NULL || to_close == NULL || to_open == NULL) {
        fprintf(stderr, "NULL argument in the file %s
                        , in the function %s
                        , on the line %d\n", __FILE__
                        , __func__, __LINE__);
        return 0;
    }
#endif

    List* lst = table_search_cell(cch->table, page);
    
    if (lst != NULL) {
        list_add_to_head(lst, time);
        tree_delete_node(cch->tree, lst);
        tree_add_value(cch->tree, lst, list_get_value(list_get_tail(lst)));

#ifdef CACHE_PAGE_LINKS_ON
        *to_close = NULL;
#endif
        return 1;
    }

    if (cch->cur_lst == cch->size) {
        List* del = tree_delete_min(cch->tree);
        list_clean(del);
        table_delete_cell(cch->table, del->value);

#ifdef CACHE_PAGE_LINKS_ON
        *to_close = del->value;
#endif

        del->value = page;
        table_add_value(cch->table, del, page);
        list_add_to_head(del, time);
        tree_add_value(cch->tree, del, time);

    } else {
        cch->lists[cch->cur_lst]->value = page;
        table_add_value(cch->table, cch->lists[cch->cur_lst], page);
        tree_add_value(cch->tree, cch->lists[cch->cur_lst], time);
        cch->cur_lst += 1;

#ifdef CACHE_PAGE_LINKS_ON
        *to_close = NULL;
#endif
    }

    return 0;
}

void delete_cache(struct cache* cch) {
    delete_table(cch->table);
    delete_tree (cch->tree);

    for (size_t i = 0; i < cch->size; ++i) {
        delete_list(cch->lists[i]);
    }

    free(cch->lists);
    free(cch);
}
