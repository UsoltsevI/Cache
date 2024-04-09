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
struct cache* create_cache(size_t size) {
    struct cache* cch = (struct cache* ) calloc(1, sizeof(struct cache));

    cch->tbl = create_table(size);
    cch->lst = create_list(size);

    return cch;
}

int cache(struct cache* cch, CacheValueType value) {
    struct node* nd; // C90 style, but problem_LC requires it...

    // There is no need to do anything if 
    // value == the_last_value in the cache
    if (get_value(get_head(cch->lst)) == value) {
        return 1;
    }

    // removes cell from table
    nd = delete_cell(cch->tbl, value);
    
    // if the sutable cell has been founded
    // just move it to the head
    if (nd != NULL) {
        move_to_head(cch->lst, nd);
        return 1;
    }

    // if there is no such cell in the table
    // just adding this value to the list's head
    // (the tail removes automatically, see the list's implementation)
    add_to_head(cch->lst, value);

    return 0;
}

// destructor
void delete_cache(struct cache* cch) {
    delete_table(cch->tbl);
    delete_list(cch->lst);
    free(cch);
}
