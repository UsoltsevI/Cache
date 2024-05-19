//--------------------------------------------------------------------------------------------------
//
// Input: 2 files in arguments of main first is a data file
// and second is a file with results generated by test_generator
// Output: result of the selected test
//
// Compares the results of the lru-k with the result of the operation of the generator 
//
//--------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "../include/cache.h"

TCachePage get_page(int key) {
  return key;
}

int main(int argc, char *argv[]) {
  FILE *test_file=fopen(argv[1], "r");

  FILE *check_file=fopen(argv[2], "r");

  size_t k;

  fscanf(test_file, "%d", &k);

  size_t cache_size=0;

  fscanf(test_file, "%d", &cache_size);

  struct cache* cch=create_cache(cache_size, k);


  size_t test_count=0;

  fscanf(test_file, "%d", &test_count);


  int *test_results=(int *) calloc(test_count, sizeof(int));


  size_t in_value=0;


  for (size_t i=0; i < test_count; i++) {
    fscanf(test_file, "%d", &in_value);

    test_results[i]=cache_update(cch, in_value, &get_page);
  }


  int *check_values=(int *) calloc(test_count, sizeof(int));

  for (size_t i=0; i < test_count; i++) {
    fscanf(check_file, "%d", check_values+i);
  }

  fclose(test_file);

  for (size_t i=0; i < test_count; i++) {
    if (check_values[i] !=test_results[i]) {
      printf("» value №%lu result - error.\n"
        " result = %d. Expected: %d", i, test_results[i], check_values[i]);
      return 0;
    }
  }

  printf("test passed\n");

  return 0;
}