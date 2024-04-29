#ifndef CACHE_H
#define CACHE_H

#include <stddef.h>

// TCacheValue == page link type
typedef size_t TCacheValue;
typedef size_t TCacheTime;

typedef struct cache TCache;
typedef struct history THist;

typedef struct hist_last_time THistLastTime;

// constructor
// size == number of stored pages
struct cache* create_cache(size_t size, size_t k);

// updates cache
// adds a link to the page to be closed to to_close
// returns 0 if miss
// returns 1 if hit
int cache(struct cache* cch
            , const TCacheValue page
            , TCacheTime time
#ifdef CACHE_PAGE_LINKS_ON
            , TCacheValue* to_close
#endif
            );

// destructor
void delete_cache(struct cache* cch);

#define CACHE_DEBUGON
#ifdef CACHE_DEBUGON
void hist_dump(THist* hist);
void cache_dump(struct cache* cch);
#endif

#endif // CACHE_H