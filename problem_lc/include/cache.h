#ifndef CACHE_H_INCLUDED
#define CACHE_H_INCLUDED

typedef int CacheValueType;
struct cache_LRU;

// constructor
struct cache_LRU* create_cache_LRU(size_t size);

// This function adds the value to cache_LRU
// and returns 1 if hit, 0 if miss
int cache_LRU(struct cache_LRU* cch, CacheValueType value);

// destructor
void delete_cache_LRU(struct cache_LRU* cch);

#endif // CACHE_H_INCLUDED
