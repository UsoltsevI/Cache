
//------------------------------------------------------------------------------
//
// Tree header
//
//------------------------------------------------------------------------------
//
// This is a header for my implementation 
// of the red-black binary tree
//
//------------------------------------------------------------------------------

#ifndef TREE_H
#define TREE_H

#include "cache.h"

typedef THist* TTreeContent;

typedef double time;

enum rbtree_node_color { RED, BLACK };

typedef struct rbtree_node_t* rbtree_node;

typedef struct rbtree_t* rbtree;

typedef int (*compare_func)(void* left, void* right);

rbtree rbtree_create ();

size_t rbtree_lookup (rbtree t, size_t key, compare_func compare);

void rbtree_insert (rbtree t, size_t key, TTreeContent data, compare_func compare);

void rbtree_delete (rbtree t, size_t key, compare_func compare);

int compare_time(void* leftp, void* rightp);

typedef rbtree_node node;
typedef enum rbtree_node_color color;

TTreeContent tree_delete_min (rbtree t, compare_func compare);

void rbtree_clean (rbtree t);

#ifdef CACHE_DEBUGON
    void draw_tree (rbtree tree);
    void rbtree_dump(rbtree tree);
#endif

#endif // TREE_H