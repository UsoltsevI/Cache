#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/cache.h"

struct cache {
    struct table* tbl;
    struct list* lst;
};

// constructor
struct cache* create_cache_LRU(size_t size) {
    struct cache* cch = (struct cache* ) calloc(1, sizeof(struct cache));

    cch->tbl = create_table(size);
    cch->lst = create_list(size);

    return cch;
}

int cache_LRU(struct cache* cch, CacheValueType value) {
    struct node* nd; // C90 style, but problem_LC requires it...

    nd = search_cell(cch->tbl, value);

    // printf("value = %u\n", value);

    // if the sutable cell has been founded
    // just move it to the head
    if (nd != NULL) {
        move_to_head(cch->lst, nd);

        // printf("HIT!\n");
        // list_dump(cch->lst);
        // print_hash_table(cch->tbl);
        // printf("\n");

        return 1;
    }

    // if there is no such cell in the table
    // delete tail from table
    delete_cell(cch->tbl, get_value(get_tail(cch->lst)));
    // Then, adding this value to the list's head
    // (the tail removes automatically, see the list's implementation)
    add_to_head(cch->lst, value);
    // and, finally, adds this node to hashmap
    add_value(cch->tbl, get_head(cch->lst), value);

    // printf("MISS!\n");
    // list_dump(cch->lst);
    // print_hash_table(cch->tbl);
    // printf("\n");

    return 0;
}

// destructor
void delete_cache_LRU(struct cache* cch) {
    delete_table(cch->tbl);
    delete_list(cch->lst);
    free(cch);
}
