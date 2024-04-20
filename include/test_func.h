#ifndef TEST_FUNC_H
#define TEST_FUNC_H

int* create_random_arr(int size);

void delete_arr( int* arr, int size);

double get_time_LRU(int* arr, int size_cache);

int get_hits_LRU(int* arr, int size_cache);

double get_time_LRU_K(int* arr, int size_cache, int k);

int get_hits_LRU_K(int* arr, int size_cache, int k);

#endif
