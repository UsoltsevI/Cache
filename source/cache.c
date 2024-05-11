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
    THist* first_struct  = (THist*) first;
    THist* second_struct = (THist*) second;
#if 1
    if (first_struct->last_itr < second_struct->last_itr) {
        return -1;
    } else if (first_struct->last_itr > second_struct->last_itr) {
        return 1;
    }

    return 0;
#else
    return first_struct->last_itr - second_struct->last_itr;
#endif
}

TCache* create_cache(size_t size, size_t k) {
    TCache* cch = (TCache*) calloc(1, sizeof(TCache));

    cch->size = size;
    cch->k    = k;

    cch->table = create_table(cch->size);
    cch->tree  = rbtree_create();
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
                hst->node = NULL; // DEBUG
                rbtree_insert(cch->tree, hst, &compare_hist_itr);

            } else {
                list_move_to_head(cch->list, hst->node);
            }

        } else {
            rbtree_delete(cch->tree, hst, &compare_hist_itr);

            queue_add_to_head(hst->queue, cch->iteration);

            hst->last_itr = queue_get_tail(hst->queue);

            assert(hst->last_itr != MINUS_INF); // DEBUG
            assert(hst->node == NULL);          // DEBUG

            rbtree_insert(cch->tree, hst, &compare_hist_itr);
        }

        return 1;
    }

    if (cch->cur_hst == cch->size) {
        if (list_num_elem(cch->list) > 0) {
            hst = list_get_value(list_get_tail(cch->list));

            assert(hst->node != NULL);          // DEBUG
            assert(hst->last_itr == MINUS_INF); // DEBUG

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
                hst->node = NULL; // DEBUG
                rbtree_insert(cch->tree, hst, &compare_hist_itr);
            }

        } else {
            hst = tree_delete_min(cch->tree, &compare_hist_itr);

            assert(hst->node == NULL);          // DEBUG
            assert(hst->last_itr != MINUS_INF); // DEBUG

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
                rbtree_insert(cch->tree, hst, &compare_hist_itr);
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
            hst->node = NULL; // DEBUG
            rbtree_insert(cch->tree, hst, &compare_hist_itr);
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
