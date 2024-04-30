#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/cache.h"

struct cache_LRU {
    struct table* tbl;
    struct list* lst;
};

// constructor
struct cache_LRU* create_cache_LRU(size_t size) {
    struct cache_LRU* cch = (struct cache_LRU* ) calloc(1, sizeof(struct cache_LRU));

    cch->tbl = create_table_LRU(size);
    cch->lst = create_list_LRU(size);

    return cch;
}

int cache_LRU(struct cache_LRU* cch, CacheValueType value) {
    struct node* nd; // C90 style, but problem_LC requires it...

    nd = search_cell_LRU(cch->tbl, value);

    // printf("value = %u\n", value);

    // if the sutable cell has been founded
    // just move it to the head
    if (nd != NULL) {
        move_to_head_LRU(cch->lst, nd);

        // printf("HIT!\n");
        // list_dump(cch->lst);
        // print_hash_table(cch->tbl);
        // printf("\n");

        return 1;
    }

    // if there is no such cell in the table
    // delete tail from table
    delete_cell_LRU(cch->tbl, get_value_LRU(get_tail_LRU(cch->lst)));
    // Then, adding this value to the list's head
    // (the tail removes automatically, see the list's implementation)
    add_to_head_LRU(cch->lst, value);
    // and, finally, adds this node to hashmap
    add_value_LRU(cch->tbl, get_head_LRU(cch->lst), value);

    // printf("MISS!\n");
    // list_dump(cch->lst);
    // print_hash_table(cch->tbl);
    // printf("\n");

    return 0;
}

// destructor
void delete_cache_LRU(struct cache_LRU* cch) {
    delete_table_LRU(cch->tbl);
    delete_list_LRU(cch->lst);
    free(cch);
}
