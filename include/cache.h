#ifndef CACHE_H
#define CACHE_H

#include <stddef.h>

typedef size_t TCacheValue;
struct cache;

typedef size_t TCacheTime;

struct cache* create_cache(size_t size, size_t k);

int cache(struct cache* cch
            , const TCacheValue* page
            , TCacheTime time
#ifdef CACHE_PAGE_LINKS_ON
            , TCacheValue* to_close
#endif
            );

void delete_cache(struct cache* cch);

#endif // CACHE_H