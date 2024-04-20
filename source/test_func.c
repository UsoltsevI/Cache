#include <stdio.h>
#include <stdlib.h>
#include <calloc.h>
#include <time.h>
#include "..problem_lc/include/hash.h"
#include "..problem_lc/include/cache.h"
#include "..include/cache.h"
#include "..include/hash.h"


int* create_random_arr(int size) {
    int* arr = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; ++i) {
        arr[i] = rand();
    }
    return arr;
}

void delete_arr( int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        free(arr[i]);
    }
}

double get_time_LRU(int* arr, int size_cache) {
    clock_t start, end;
    double tm = 0;
    struct cache* cch = NULL;
    int res = 0;


    cch = create_cache_LRU(size_cache);

    for(int i = 0; i < size_random_arr; ++i) {
        start = clock();
        res = cache_LRU(cch, arr[i]);
        end = clock();
        tm += (double)(end - start) / CLOCKS_PER_SEC;
    }

    delete_cache_LRU(cch);

    return tm;
}

double get_time_LRU_K(int* arr, int size_cache, int k) {
    clock_t start, end;
    double tm = 0;
    struct cache* cch = NULL;
    int res = 0;


    cch = create_cache(size_cache, k);

    for(int i = 0; i < size_random_arr; ++i) {
        start = clock();
        res = cache(cch, arr[i], i);
        end = clock();
        tm += (double)(end - start) / CLOCKS_PER_SEC;
    }

    delete_cache(cch);

    return tm;
}

int get_hits_LRU(int* arr, int size_cache) {
    struct cache* cch = NULL;
    int res = 0, cou = 0;

    cch = create_cache_LRU(size_cache);

    for(int i = 0; i < size_random_arr; ++i) {
        res = cache_LRU(cch, arr[i]);
        cou += res;
    }

    delete_cache_LRU(cch);

    return cou;
}

int get_hits_LRU_K(int* arr, int size_cache, int k) {
    struct cache* cch = NULL;
    int res = 0, cou = 0;

    cch = create_cache_LRU(size_cache);

    for(int i = 0; i < size_random_arr; ++i) {
        res = cache_LRU(cch, arr[i]);
        cou += res;
    }

    delete_cache_LRU(cch);

    return cou;
}



