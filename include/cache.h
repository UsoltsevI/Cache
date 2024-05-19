//------------------------------------------------------------------------------
//
// Cache LRU-K header
//
//------------------------------------------------------------------------------
//
// This is a universal header for any implementation 
// of the LRU-K caching algorithm
//
//------------------------------------------------------------------------------

#ifndef CACHE_H
#define CACHE_H

#include <stddef.h>

typedef size_t TCachePage;
typedef size_t TCacheKey;

typedef struct cache TCache;
typedef struct history THist;

struct cache* create_cache(size_t size, size_t k);

// updates cache
// returns 0 if miss, returns 1 if hit
int cache_update(TCache* cch
            , int key
            , TCachePage (*get_page) (int));

void delete_cache(TCache* cch);

// #define CACHE_DEBUGON
#ifdef CACHE_DEBUGON
    // void hist_dump(THist* hist);
    // void cache_dump(struct cache* cch);

    TCacheKey hist_get_key(THist* hist);
    size_t hist_get_last_itr(THist* hist);
#endif

#endif // CACHE_H