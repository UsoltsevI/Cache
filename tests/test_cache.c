#include <stdio.h>
#include <stdlib.h>

#include "../include/cache.h"

TCachePage get_page(int key) {
    return key;
}

int main(int argc, char *argv[])
{
FILE *test_file = fopen(argv[1], "r");

size_t k;

fscanf(test_file, "%d", &k);

size_t cache_size = 0;

fscanf(test_file, "%d", &cache_size);

struct cache* cch = create_cache(cache_size,k);


size_t test_count = 0;

fscanf(test_file, "%d", &test_count);


int *test_results = (int *) calloc(test_count, sizeof(int));


size_t in_value = 0;


for (size_t i = 0; i < test_count; i++)
{
fscanf(test_file, "%d", &in_value);

test_results[i] = cache_update(cch, in_value,&get_page);
}


int *check_values = (int *) calloc(test_count, sizeof(int));

for (size_t i = 0; i < test_count; i++)
{
scanf("%d", check_values + i);
}

fclose(test_file);

for (size_t i = 0; i < test_count; i++)
{
if (check_values[i] == test_results[i])
{
printf("» Test №%lu - passed\n", i);
}
else
{
printf("» Test №%lu result - error.\n"
" Test result = %d. Expected: %d", i, test_results[i], check_values[i]);
}
}

return 0;
}