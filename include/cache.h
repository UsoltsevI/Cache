#ifndef CACHE_H
#define CACHE_H

#include <stddef.h>

typedef size_t TCachePage;
typedef size_t TCacheKey;

typedef struct cache TCache;
typedef struct history THist;

// constructor
// size == number of stored pages
struct cache* create_cache(size_t size, size_t k);

// updates cache, adds a link to the 
// page to be closed to to_close
// returns 0 if miss, returns 1 if hit
int cache_update(TCache* cch
            , int key
            , TCachePage (*get_page) (int));

// destructor
void delete_cache(TCache* cch);

// #define CACHE_DEBUGON
#ifdef CACHE_DEBUGON
    void hist_dump(THist* hist);
    void cache_dump(struct cache* cch);
    TCacheTime hist_get_time(THist* hist);
#endif

#endif // CACHE_H