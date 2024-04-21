#include "../include/test_func.h"
#include <stdio.h>
#include <malloc.h>
#include <stddef.h>

int main() {
    FILE* fl = fopen("../home/answer_table.csv", "a+");
    int* rnd = NULL, opt = NULL;
    int n = 0;

    fprintf(fl,"num of values, ");
    printf("write the number of LRU_K\n");
    scanf("%i\n", &n);
    opt = (int*)calloc(n * 2 + 1, sizeof(int));
    for(int t = 0; i < n; ++i) {
        printf("write length and k\n");
        scanf("%i %i\n", &opt[t * 2], &opt[t * 2 + 1];
        fprintf(fl, "length = %i K = %i, ", opt[t * 2], opt[t * 2 + 1]);
    }
    printf("write length of LRU\n");
    scanf("%i" &opt[n * 2]);
    fprintf(fl, "length = %i\n, 1) time, 2) hits\n", opt[n * 2]);

    for(int i = 10; i <= 10000000; i * 10) {
        arr = create_random_arr(i);
        fprintf(fl, "%i, " i);
        for(int j = 0; j < n; ++j) {
            fprintf(fl, "%d, ", get_time_LRU_K(arr, opt[j * 2], opt[j * 2 + 1]);
        }
        fprintf(fl, "%d", get_time_LRU(arr, opt[n * 2]);
        for(int p = 0; p < n; ++p) {
            fprintf(fl, "%i, ", get_hits_LRU_K(arr, opt[p * 2], opt[p * 2 + 1]);
        }
        fprintf(fl, "%i\n", get_hits_LRU(arr, opt[n * 2]);
        delete_arr(arr);
    }
    fclose(fl);
    free(opt);
}
