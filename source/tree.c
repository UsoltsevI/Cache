#include "include/tree.h"
#include <stdlib.h>

struct tree_node {
    Node* left;
    Node* right;

    enum node_type color;
};

Node* create_tree() {
    Node* tree = (Node*)calloc(1, sizeof(Node));

    return tree;
}