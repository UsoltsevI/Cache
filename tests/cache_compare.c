#include "../problem_lc/include/cache.h"
#include "../include/cache.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#define DEFAULT_FILE "res_compare.csv"

int* create_random_arr(size_t size);

void delete_arr(int* arr);

int get_hits_LRU(int* arr, size_t size_arr, size_t size_cache);

int get_hits_LRU_K(int* arr, size_t size_arr, size_t size_cache, int k);

int* create_random_arr(size_t size) {
    int* arr = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; ++i) {
        arr[i] = rand();
    }
    return arr;
}

void delete_arr(int* arr) {
    free(arr);
}

int get_hits_LRU(int* arr, size_t size_arr,  size_t size_cache) {
    struct cache_LRU* cch = create_cache_LRU(size_cache);
    int res = 0, cou = 0;

    for(int i = 0; i < size_arr; ++i) {
        res = cache_LRU(cch, arr[i]);
        cou += res;
    }

    delete_cache_LRU(cch);

    return cou;
}

int get_hits_LRU_K(int* arr, size_t size_arr,  size_t size_cache, int k) {
    struct cache* cch = create_cache(size_cache, k);
    int res = 0, cou = 0;

    for(int i = 0; i < size_arr; ++i) {
        res = cache(cch, arr[i], time(NULL));
        cou += res;
    }

    delete_cache(cch);

    return cou;
}

int main(int argc, char* argv[]) {
    FILE* fl = NULL;
    int* arr = NULL;
    int* opt = NULL;
    int num_hits = 0;
    int n = 0;
    clock_t start = 0, end = 0;
    double tm = 0;

    if (argc != 0) {
        fl = fopen(argv[0], "a+");
    }
    else {
        fl = fopen(DEFAULT_FILE, "a+");
    }

    fprintf(fl, "Num of values, ");
    printf("write the number of LRU_K\n");
    scanf("%i", &n);
    opt = (int*)calloc(n * 2 + 1, sizeof(int));

    printf("write length of LRU\n");
    scanf("%i", &opt[n * 2]);
    fprintf(fl, "LRU time   (len = %i), LRU hits    (len = %i), ", opt[n * 2], opt[n * 2]);
    for(int t = 0; t < n; ++t) {
        printf("write length and k\n");
        scanf("%i %i", &opt[t * 2], &opt[t * 2 + 1]);
        fprintf(fl, "LRU_K-%i time  (len = %i K = %i), ", t + 1, opt[t * 2], opt[t * 2 + 1]);
        fprintf(fl, "LRU_K-%i hits  (len = %i K = %i), ", t + 1, opt[t * 2], opt[t * 2 + 1]);
    }
    fprintf(fl,"\n");

    for(int i = 10; i <= 10000000; i * 10) {
        arr = create_random_arr(i);

        fprintf(fl, "%i           , ", i);

        start = clock();
        num_hits = get_hits_LRU(arr, i, opt[n * 2]);
        end = clock();
        tm = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(fl, "%d, %i         , ", tm, num_hits);

        for(int j = 0; j < n; ++j) {
            start = clock();
            num_hits = get_hits_LRU_K(arr, i, opt[j * 2], opt[j * 2 + 1]);
            end = clock();
            tm = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(fl, "%d     , %i             , ", tm, num_hits);
        }
        
        fprintf(fl, "\n");
        delete_arr(arr);
    }

    fclose(fl);
    free(opt);
    free(num_hits);
}