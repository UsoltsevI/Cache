//--------------------------------------------------------------------------------------------------
//
// Input: length of LRU and parameters of LRU-K
// Output: csv file with time and hits for arrays with diffrent length
//
// You can use diffrent options for distributing values in arrays
// For this you can sumbit code words to main in first argument:
// fluct - to fluctuate values within a random number +- HIGHT_FLUCT and with length = LENGTH_FLUCT
// saw - to monotonically increasing values with step 1 from random value to random value + SIZE_SAW
// rand - to distributing values in arrays is random in range from 0 to MAX_RANDOM
// Deafault distributing values in arrays is random in range from 0 to MAX_RANDOM
//
// If you want to use your name of file with results you can write it in second argument of main
// Deafault name of file with results is res_compare.csv
//
//--------------------------------------------------------------------------------------------------

#include "../problem_lc/include/cache.h"
#include "../include/cache.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#define DEFAULT_FILE "res_compare.csv"
#define SIZE_SAW 1000000
#define HIGHT_FLUCT 8
#define LENGTH_FLUCT 100
#define MAX_RANDOM 50000

int* create_random_arr(size_t size);
int* create_saw_arr(size_t size);
int* create_fluct_arr(size_t size);

void delete_arr(int* arr);

size_t get_page(int i);

int get_hits_LRU(int* arr, size_t size_arr, size_t size_cache);

int get_hits_LRU_K(int* arr, size_t size_arr, size_t size_cache, int k);

int* create_random_arr(size_t size) {
    int* arr = (int*)calloc(size, sizeof(int));

    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % MAX_RANDOM;
    }
    return arr;
}

int* create_saw_arr(size_t size) {
    int* arr = (int*)calloc(size, sizeof(int));
    int start = rand() % (INT_MAX - SIZE_SAW);

    for(int i = 0; i < size; ++i) {
        arr[i] = start + i % SIZE_SAW;
    }
    return arr;
}

int* create_fluct_arr(size_t size) {
    int* arr = (int*)calloc(size, sizeof(int));
    int start = 0;

    for(int i = 0; i < size; ++i) {
        if (i % LENGTH_FLUCT == 0) {
            start = (HIGHT_FLUCT + rand() % (INT_MAX - 2 * HIGHT_FLUCT));
        }
        arr[i] = (start + rand() % (2 * HIGHT_FLUCT) - HIGHT_FLUCT);
    }

    return arr;
}

void delete_arr(int* arr) {
    free(arr);
}

size_t get_page(int i) {
    return (size_t)i;
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
        res = cache_update(cch, arr[i], get_page);
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
    int n = 0, test = 0, b = 1;
    clock_t start = 0, end = 0;
    double tm = 0;

    if (argc == 3) {
        fl = fopen(argv[2], "w+");
    }
    else {
        fl = fopen(DEFAULT_FILE, "w+");
    }

    //fprintf(fl, "Num of values, ");
    printf("write the number of LRU_K\n");
    test = scanf("%i", &n);
    assert(test == 1);
    opt = (int*)calloc(n * 2 + 1, sizeof(int));

    printf("write length of LRU\n");
    test = scanf("%i", &opt[n * 2]);
    assert(test == 1);
    //fprintf(fl, "LRU time   (len = %i), LRU hits    (len = %i), ", opt[n * 2], opt[n * 2]);
    for(int t = 0; t < n; ++t) {
        printf("write length and k\n");
        test = scanf("%i %i", &opt[t * 2], &opt[t * 2 + 1]);
        assert(test == 2);
        //fprintf(fl, "LRU_K-%i time  (len = %i K = %i), ", t + 1, opt[t * 2], opt[t * 2 + 1]);
        //fprintf(fl, "LRU_K-%i hits  (len = %i K = %i), ", t + 1, opt[t * 2], opt[t * 2 + 1]);
    }
   // fprintf(fl,"\n");
   fprintf(fl, "%s,\n", argv[1]);
//for(int a = 100; a <= 1000000; a = a * 10) {
    for(int i = 1000000; i <= 1000000; i = i * 10) {
        if (argc >= 2) {
            if (strcmp(argv[1], "saw") == 0) {
                arr = create_saw_arr(i);
            }
            else if (strcmp(argv[1], "fluct") == 0) {
                arr = create_fluct_arr(i);
            }
            else if (strcmp(argv[1], "rand") == 0) {
                arr = create_random_arr(i);
            }
            else {
                printf("ERROR: wrong name allocation\n");
            }
        }
        else {
            arr = create_random_arr(i);
        }

        //fprintf(fl, "%i           , ", i);
        //fprintf(fl, "%s,\n", argv[1]);


        start = clock();
        num_hits = get_hits_LRU(arr, i, opt[n * 2] * b);
        end = clock();
        tm = (double)(end - start) / CLOCKS_PER_SEC;
        //fprintf(fl, "%lf, %i         , ", tm, num_hits);
        //fprintf(fl, "k,     hits,\n");
        fprintf(fl, "%i,    %i,\n", 0, num_hits);
        //fprintf(fl, "%lf,   ", tm);

        for(int j = 0; j < n; ++j) {
            start = clock();
            num_hits = get_hits_LRU_K(arr, i, opt[j * 2] * b, opt[j * 2 + 1]);
            end = clock();
            tm = (double)(end - start) / CLOCKS_PER_SEC;
            //fprintf(fl, "%lf     , %i             , ", tm, num_hits);
            fprintf(fl, "%i,        %i,\n", opt[j * 2 + 1], num_hits);
           // fprintf(fl, "%lf,   ", tm);
        }
        //b = b * 10;
        fprintf(fl, "\n");
        delete_arr(arr);
    }
//}

    fclose(fl);
    free(opt);
}
