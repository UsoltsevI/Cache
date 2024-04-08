#ifndef CACHE_H_INCLUDED
#define CACHE_H_INCLUDED

struct table;
struct list;

// This function adds the value to cache 
// and returns 1 if hit, 0 if miss
int cache(struct table* tbl, struct list* lst, int value);

#endif // CACHE_H_INCLUDED