#ifndef TREE_H
#define TREE_H

#include "cache.h"

// typedef THist* TTreeContent;

typedef THistLastTime* TTreeKey;

typedef double time;

enum rbtree_node_color { RED, BLACK };

typedef struct rbtree_node_t* rbtree_node;

typedef struct rbtree_t* rbtree;

typedef int (*compare_func)(void* left, void* right);

rbtree rbtree_create ();

TTreeKey rbtree_lookup (rbtree t, TTreeKey key, compare_func compare);

void rbtree_insert (rbtree t, TTreeKey key, compare_func compare);

void rbtree_delete (rbtree t, TTreeKey key, compare_func compare);

int compare_time(void* leftp, void* rightp);

typedef rbtree_node node;
typedef enum rbtree_node_color color;

TTreeKey tree_delete_min (rbtree t, compare_func compare);

void rbtree_clean (rbtree t);

#endif // TREE_H