#ifndef CACHE_H_INCLUDED
#define CACHE_H_INCLUDED

struct cache;

// constructor
struct cache* create_cache(size_t size);

// This function adds the value to cache 
// and returns 1 if hit, 0 if miss
int cache(struct cache* cch, int value);

// destructor
void delete_cache(struct cache* cch);

#endif // CACHE_H_INCLUDED