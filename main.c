//------------------------------------------------------------------------------
//
// This file implements a function for counting the number 
// of hits when using the LRU-K caching algorithm.
//
//------------------------------------------------------------------------------
//
// The input data is received in the following format: 
// the number of pages stored in the cache, the amount 
// of data, and the data itself. The data is just page 
// numbers.
// The K value was chosen as the most optimal based on
// the results of our testing.
// 
//------------------------------------------------------------------------------

#include <stdio.h>
#include "./include/cache.h"

TCachePage get_page(int key) {
    return key;
}

int main() {
    size_t m, n;
    size_t num_hit = 0;
    struct cache* cch;
    int res = 0;

    res = scanf("%lu%lu", &m, &n);

    cch = create_cache(m, 1);

    for (size_t i = 0; i < n; ++i) {
        size_t next;
        res = scanf("%lu", &next);

        size_t last = cache_update(cch, next, &get_page);
        num_hit += last;

#ifdef CACHE_DEBUGON
        printf("number: %lu, page: %lu, result: %lu\n\n", i, next, last);
        // cache_dump(cch);
#endif
    }

    printf("%lu\n", num_hit);

    delete_cache(cch);

    return 0;
}
