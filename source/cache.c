#include <stdio.h>
#include "../include/list.h"
#include "../include/hash.h"
#include "../include/cache.h"

int cache(struct table* tbl, struct list* lst, int value) {
    struct node* nd; // C90 style, but problem_LC requires it...

    // There is no need to do anything if 
    // value == the_last_value in the cache
    if (get_value(get_head(lst)) == value) {
        return 1;
    }

    // removes cell from table
    nd = delete_cell(tbl, value);
    
    // if the sutable cell has been founded
    // just move it to the head
    if (nd != NULL) {
        move_to_head(lst, nd);
        return 1;
    }

    // if there is no such cell in the table
    // just adding this value to the list's head
    // (the tail removes automatically, see the list's implementation)
    add_to_head(lst, value);

    return 0;
}
