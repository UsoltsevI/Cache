#include "..problem_lc/include/hash.h"
#include "..problem_lc/include/cache.h"
#include "..include/cache.h"
#include "..include/hash.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#define FILE "../home/answer_table.csv"

int* create_random_arr(int size);

void delete_arr(int* arr);

double get_time_LRU(int* arr, int size_cache);

int get_hits_LRU(int* arr, int size_cache);

double get_time_LRU_K(int* arr, int size_cache, int k);

int get_hits_LRU_K(int* arr, int size_cache, int k);

int* create_random_arr(int size) {
    int* arr = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; ++i) {
        arr[i] = rand();
    }
    return arr;
}

void delete_arr(int* arr) {
    free(arr);
}

int get_hits_LRU(int* arr, int size_cache) {
    struct cache_LRU* cch = NULL;
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

    cch = create_cache_LRU(size_cache, k);

    for(int i = 0; i < size_random_arr; ++i) {
        res = cache_LRU(cch, arr[i]);
        cou += res;
    }

    delete_cache_LRU(cch);

    return cou;
}

int main() {
    FILE* fl = fopen(FILE, "a+");
    int* rnd = NULL, opt = NULL, num_hits = NULL;
    int n = 0;
    clock_t start, end;
    double tm = 0;

    fprintf(fl,"num of values, ");
    printf("write the number of LRU_K\n");
    scanf("%i\n", &n);
    num_hits = (int*)calloc(n + 1, sizeof(int));
    opt = (int*)calloc(n * 2 + 1, sizeof(int));
    for(int t = 0; i < n; ++i) {
        printf("write length and k\n");
        scanf("%i %i\n", &opt[t * 2], &opt[t * 2 + 1];
        fprintf(fl, "length = %i K = %i, ", opt[t * 2], opt[t * 2 + 1]);
    }
    printf("write length of LRU\n");
    scanf("%i\n", &opt[n * 2]);
    fprintf(fl, "length = %i\n, 1) time, 2) hits\n", opt[n * 2]);

    for(int i = 10; i <= 10000000; i * 10) {
        arr = create_random_arr(i);
        fprintf(fl, "%i, " i);
        for(int j = 0; j < n; ++j) {
            start = clock();
            num_hits[j] = get_hits_LRU_K(arr, opt[j * 2], opt[j * 2 + 1]);
            end = clock();
            tm = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(fl, "%d, " tm);
        }
        start = clock();
        num_hits[n] = get_hits_LRU(arr, opt[n * 2]);
        end = clock();
        tm = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(fl, "%d, ", tm);
        for(int p = 0; p < n; ++p) {
            fprintf(fl, "%i, ", num_hits[p]);
        }
        fprintf(fl, "%i\n", num_hits[n]);
        delete_arr(arr);
    }
    fclose(fl);
    free(opt);
    free(num_hits);
}
