#ifndef TREE_H
#define TREE_H

enum node_type
{
    BLACK = 0,
    RED = 1,
    DEFAULT = 2
};

struct tree_node;

typedef struct tree_node Node;

Node* create_tree();

#endif // TREE_H