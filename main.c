#include <stdio.h>
#include "./include/cache.h"

// This is the main function for the problem_LC
// and separate compilation task.
// You just need to copy it to LC.c before submitting.
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
        // printf("ghg\n");

        num_hit += cache(cch, next, i);
        // printf("%lu\n", num_hit);
    }

    printf("%lu\n", num_hit);

    delete_cache(cch);

    return 0;
}
