#ifndef TREE_H
#define TREE_H

enum rbtree_node_color { RED, BLACK };

typedef struct rbtree_node_t;

typedef struct rbtree_t;

typedef int (*compare_func)(void* left, void* right);

rbtree rbtree_create ();

void* rbtree_lookup (rbtree t, void* key, compare_func compare);

void rbtree_insert (rbtree t, void* key, compare_func compare);

void rbtree_delete (rbtree t, void* key, compare_func compare);

typedef rbtree_node node;
typedef enum rbtree_node_color color;

#endif // TREE_H