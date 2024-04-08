#include <stdio.h>
#include "../include/hash.h"
#include "../include/cache.h"

// This is the main function for the problem_LC
// and separate compilation task. 
// You just need to copy it to LC.c before submitting.
int main() {
    size_t m, n;
    size_t num_hit = 0;
    struct cache* cch;

    scanf("%lu%lu", &m, &n);

    cch = create_cache(m);

    for (size_t i = 0; i < n; ++i) {
        int next;
        scanf("%d", &next);

        num_hit += cache(cch, next);
    }

    printf("%lu\n", num_hit);

    delete_cache(cch);

    return 0;
}
