#include "../include/tree.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct cells {
    node* cells;
    node free_cell;
};

typedef struct cells* TreeCells;

struct rbtree_node_t {
    size_t key;
    TTreeContent data;
    struct rbtree_node_t* left;
    struct rbtree_node_t* right;
    struct rbtree_node_t* parent;
    enum rbtree_node_color color;

    int num_in_tree;
};

struct rbtree_t {
    rbtree_node root;
    TreeCells memory;
};

static node grandparent (node n);
static node sibling (node n);
static node uncle (node n);

#ifdef TREE_DEBUGON
static void verify_properties (rbtree t);
static void property_1 (node root);
static void property_2 (node root);
static color node_color (node n);
static void property_4 (node root);
static void property_5 (node root);
static void property_5_helper (node n, int black_count, int* black_count_path);
#endif

static node new_node (TreeCells memory, size_t key, TTreeContent data, color node_color, node left, node right);
static node lookup_node (rbtree t, size_t key, compare_func compare);
static void rotate_left (rbtree t, node n);
static void rotate_right (rbtree t, node n);

static void replace_node (rbtree t, node oldn, node newn);
static void insert_case1 (rbtree t, node n);
static void insert_case2 (rbtree t, node n);
static void insert_case3 (rbtree t, node n);
static void insert_case4 (rbtree t, node n);
static void insert_case5 (rbtree t, node n);
static node maximum_node (node root);
static void delete_case1 (rbtree t, node n);
static void delete_case2 (rbtree t, node n);
static void delete_case3 (rbtree t, node n);
static void delete_case4 (rbtree t, node n);
static void delete_case5 (rbtree t, node n);
static void delete_case6 (rbtree t, node n);

static void tree_search_min (node n, node* min, compare_func compare);

TreeCells create_cells (size_t size);
node get_free_cell (TreeCells memory);

void draw_tree_1 (FILE* save, node tree, int* node_num);

void draw_tree_2 (FILE* save, node tree);

void rbtree_clean_ (node t);

int compare_time(void* leftp, void* rightp) {
    time left = *(time*)leftp;
    time right = *(time*)rightp;
    if (left < right) 
        return -1;
    else if (left > right)
        return 1;
    else {
        assert (left == right);
        return 0;
    }
}

node grandparent (node n) {
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return n->parent->parent;
}

node sibling (node n) {
    assert (n != NULL);
    assert (n->parent != NULL);
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

node uncle (node n) {
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return sibling(n->parent);
}

#ifdef TREE_DEBUGON
void verify_properties (rbtree t) {
    property_1(t->root);
    property_2(t->root);
    property_4(t->root);
    property_5(t->root);
}

void property_1 (node n) {
    assert(node_color(n) == RED || node_color(n) == BLACK);
    if (n == NULL) return;
    property_1(n->left);
    property_1(n->right);
}

void property_2 (node root) {
    assert(node_color(root) == BLACK);
}
#endif
color node_color (node n) {
    return n == NULL ? BLACK : n->color;
}

#ifdef TREE_DEBUGON
void property_4 (node n) {
    if (node_color(n) == RED) {
        assert (node_color(n->left)   == BLACK);
        assert (node_color(n->right)  == BLACK);
        assert (node_color(n->parent) == BLACK);
    }
    if (n == NULL) return;
    property_4(n->left);
    property_4(n->right);
}

void property_5 (node root) {
    int black_count_path = -1;
    property_5_helper(root, 0, &black_count_path);
}

void property_5_helper (node n, int black_count, int* path_black_count) {
    if (node_color(n) == BLACK) {
        black_count++;
    }
    if (n == NULL) {
        if (*path_black_count == -1) {
            *path_black_count = black_count;

        } else {
            assert (black_count == *path_black_count);
        }

        return;
    }

    property_5_helper(n->left,  black_count, path_black_count);
    property_5_helper(n->right, black_count, path_black_count);
}
#endif

rbtree rbtree_create (size_t size) {
    rbtree t = malloc(sizeof(struct rbtree_t));
    t->root = NULL;

#ifdef TREE_DEBUGON
    verify_properties(t);
#endif

    t->memory = create_cells(size);

    return t;
}

TreeCells create_cells (size_t size) {
    TreeCells memory = (TreeCells)calloc(1, sizeof(struct cells));
    memory->cells = (node*)calloc(size, sizeof(struct rbtree_node_t));
    memory->free_cell = memory->cells[0];

    return memory;
}

node get_free_cell (TreeCells memory) {
    node free_cell = memory->free_cell;
    memory->free_cell += 1;
    return free_cell;
}

node new_node (TreeCells memory, size_t key, TTreeContent data, color node_color, node left, node right) {
    node result = get_free_cell(memory);
    result->key = key;
    result->color = node_color;
    result->left = left;
    result->right = right;
    result->data = data;

    result->num_in_tree = 0;

    if (left  != NULL)  {
        left->parent = result;
    }

    if (right != NULL) {
        right->parent = result;
    }

    result->parent = NULL;
    return result;
}

node lookup_node (rbtree t, size_t key, compare_func compare) {
    node n = t->root;
    while (n != NULL) {
        int comp_result = compare(&key, &n->key);

        if (comp_result == 0) {
            return n;

        } else if (comp_result < 0) {
            n = n->left;

        } else {
            assert(comp_result > 0);
            n = n->right;
        }
    }
    return n;
}

size_t rbtree_lookup (rbtree t, size_t key, compare_func compare) {
    node n = lookup_node(t, key, compare);
    return n == NULL ? 0 : n->key;
}

void rotate_left (rbtree t, node n) {
    node r = n->right;
    replace_node(t, n, r);
    n->right = r->left;

    if (r->left != NULL) {
        r->left->parent = n;
    }

    r->left = n;
    n->parent = r;
}

void rotate_right (rbtree t, node n) {
    node L = n->left;
    replace_node(t, n, L);
    n->left = L->right;

    if (L->right != NULL) {
        L->right->parent = n;
    }

    L->right = n;
    n->parent = L;
}

void replace_node (rbtree t, node oldn, node newn) {
    if (oldn->parent == NULL) {
        t->root = newn;

    } else {
        if (oldn == oldn->parent->left) {
            oldn->parent->left = newn;
        } else {
            oldn->parent->right = newn;
        }
    }

    if (newn != NULL) {
        newn->parent = oldn->parent;
    }
}

void rbtree_insert (rbtree t, size_t key, TTreeContent data, compare_func compare) {
    node inserted_node = new_node(t->memory, key, data, RED, NULL, NULL);

    if (t->root == NULL) {
        t->root = inserted_node;

    } else {
        node n = t->root;

        while (1) {
            int comp_result = compare(&key, &n->key);

            if (comp_result == 0) {
                free (inserted_node);
                return;

            } else if (comp_result < 0) {
                if (n->left == NULL) {
                    n->left = inserted_node;
                    break;

                } else {
                    n = n->left;
                }

            } else {
                assert (comp_result > 0);

                if (n->right == NULL) {
                    n->right = inserted_node;
                    break;

                } else {
                    n = n->right;
                }
            }
        }

        inserted_node->parent = n;
    }

    insert_case1(t, inserted_node);

#ifdef TREE_DEBUGON
    verify_properties(t);
#endif
}

void insert_case1 (rbtree t, node n) {
    if (n->parent == NULL) {
        n->color = BLACK;

    } else {
        insert_case2(t, n);
    }
}

void insert_case2 (rbtree t, node n) {
    if (node_color(n->parent) == BLACK) {
        return;

    } else {
        insert_case3(t, n);
    }
}

void insert_case3 (rbtree t, node n) {
    if (node_color(uncle(n)) == RED) {
        n->parent->color = BLACK;
        uncle(n)->color = BLACK;
        grandparent(n)->color = RED;
        insert_case1(t, grandparent(n));

    } else {
        insert_case4(t, n);
    }
}

void insert_case4 (rbtree t, node n) {
    if (n == n->parent->right && n->parent == grandparent(n)->left) {
        rotate_left(t, n->parent);
        n = n->left;

    } else if (n == n->parent->left && n->parent == grandparent(n)->right) {
        rotate_right(t, n->parent);
        n = n->right;
    }

    insert_case5(t, n);
}

void insert_case5 (rbtree t, node n) {
    n->parent->color = BLACK;
    grandparent(n)->color = RED;

    if (n == n->parent->left && n->parent == grandparent(n)->left) {
        rotate_right(t, grandparent(n));

    } else {
        assert (n == n->parent->right && n->parent == grandparent(n)->right);
        rotate_left(t, grandparent(n));
    }
}

void rbtree_delete (rbtree t, size_t key, compare_func compare) {
    node child;
    node n = lookup_node(t, key, compare);

    if (n == NULL) {
        return;
    }

    if (n->left != NULL && n->right != NULL) {
        node pred = maximum_node(n->left);
        n->key   = pred->key;
        n = pred;
    }

    assert(n->left == NULL || n->right == NULL);
    child = n->right == NULL ? n->left  : n->right;

    if (node_color(n) == BLACK) {
        n->color = node_color(child);
        delete_case1(t, n);
    }

    replace_node(t, n, child);

    if (n->parent == NULL && child != NULL) {
        child->color = BLACK;
    }
    t->memory->free_cell = n;
    n->key = 0;

#ifdef TREE_DEBUGON
    verify_properties(t);
#endif
}

static node maximum_node (node n) {
    assert (n != NULL);

    while (n->right != NULL) {
        n = n->right;
    }

    return n;
}

void delete_case1 (rbtree t, node n) {
    if (n->parent == NULL) {
        return;
    } else {
        delete_case2(t, n);
    }
}

void delete_case2 (rbtree t, node n) {
    if (node_color(sibling(n)) == RED) {
        n->parent->color = RED;
        sibling(n)->color = BLACK;

        if (n == n->parent->left) {
            rotate_left(t, n->parent);
        } else {
            rotate_right(t, n->parent);
        }
    }

    delete_case3(t, n);
}

void delete_case3 (rbtree t, node n) {
    if (node_color(n->parent) == BLACK &&
            node_color(sibling(n)) == BLACK &&
            node_color(sibling(n)->left) == BLACK &&
            node_color(sibling(n)->right) == BLACK) {
        sibling(n)->color = RED;
        delete_case1(t, n->parent);

    } else {
        delete_case4(t, n);
    }
}

void delete_case4 (rbtree t, node n) {
    if (node_color(n->parent) == RED &&
            node_color(sibling(n)) == BLACK &&
            node_color(sibling(n)->left) == BLACK &&
            node_color(sibling(n)->right) == BLACK) {

        sibling(n)->color = RED;
        n->parent->color = BLACK;

    } else {
        delete_case5(t, n);
    }
}

void delete_case5 (rbtree t, node n) {
    if (n == n->parent->left &&
            node_color(sibling(n)) == BLACK &&
            node_color(sibling(n)->left) == RED &&
            node_color(sibling(n)->right) == BLACK) {
        sibling(n)->color = RED;
        sibling(n)->left->color = BLACK;
        rotate_right(t, sibling(n));

    } else if (n == n->parent->right &&
            node_color(sibling(n)) == BLACK &&
            node_color(sibling(n)->right) == RED &&
            node_color(sibling(n)->left) == BLACK) {
        sibling(n)->color = RED;
        sibling(n)->right->color = BLACK;
        rotate_left(t, sibling(n));
    }

    delete_case6(t, n);
}

void delete_case6 (rbtree t, node n) {
    sibling(n)->color = node_color(n->parent);
    n->parent->color = BLACK;

    if (n == n->parent->left) {
        assert (node_color(sibling(n)->right) == RED);
        sibling(n)->right->color = BLACK;
        rotate_left(t, n->parent);

    } else {
        assert (node_color(sibling(n)->left) == RED);
        sibling(n)->left->color = BLACK;
        rotate_right(t, n->parent);
    }
}

size_t tree_delete_min (rbtree t, compare_func compare) {
    node min = t->root;
    tree_search_min(t->root, &min, compare);
    
    size_t res = min->key;

    rbtree_delete(t, min->key, compare);
    return res;
}

void tree_search_min (node n, node* min, compare_func compare) {
    if (compare(&n->key, &(*min)->key) < 0) {
        *min = n;
    }

    if (n->left != NULL) {
        tree_search_min(n->left, min, compare);
    }
}

void rbtree_clean (rbtree t) {
    rbtree_clean_(t->root);
    free(t);
}

void rbtree_clean_ (node t) {
    if (t->left != NULL)
        rbtree_clean_(t->left);

    if (t->right != NULL)
        rbtree_clean_(t->right);

    free(t);
}


#ifdef CACHE_DEBUGON
    void draw_tree (rbtree tree) {
        FILE* save = fopen("drawTree.txt", "wb");

        fprintf(save, "digraph Tree {\n");

        int node_num = 0;
        draw_tree_1(save, tree->root, &node_num);
        draw_tree_2(save, tree->root);

        fprintf(save, "}");

        fclose(save);

        system("iconv -f WINDOWS-1251 -t UTF-8 drawTree.txt > buffer.txt");
        system("dot buffer.txt -Tpng -o drawTree.png");
        system("start drawTree.png");
    }

    void draw_tree_1 (FILE* save, node tree, int* node_num) {
        tree->num_in_tree = *node_num;

        if (tree->color == BLACK) {
            fprintf(save, "    %d [shape = Mrecord, style = filled, fillcolor = black, label = %c | DATA: %u%c];\n", *node_num, '"', hist_get_time(tree->key), '"');
        }
        else if (tree->color == RED) {
            fprintf(save, "    %d [shape = Mrecord, style = filled, fillcolor = red, label = %c | DATA: %u%c];\n", *node_num, '"', hist_get_time(tree->key), '"');
        }

        if (tree->left != NULL) {
            *node_num += 1;
            draw_tree_1(save, tree->left, node_num);
        }

        if (tree->right != NULL) {
            *node_num += 1;
            draw_tree_1(save, tree->right, node_num);
        }
    }

    void draw_tree_2 (FILE* save, node tree) {
        if (tree->left != NULL) {
            fprintf(save, "    %d -> %d;\n", tree->num_in_tree, (tree->left)->num_in_tree);
            draw_tree_2(save, tree->left);
        }

        if (tree->right != NULL) {
            fprintf(save, "    %d -> %d;\n", tree->num_in_tree, (tree->right)->num_in_tree);
            draw_tree_2(save, tree->right);
        }
    }

    static void node_dump(node n) {
        printf("(");
        if (n->left) {
            node_dump(n->left);
        }

        printf("%d", hist_get_time(n->key));

        if (n->right) {
            node_dump(n->right);
        }

        printf(")");
    }

    void rbtree_dump(rbtree tree) {
        if (tree->root) {
            node_dump(tree->root);
        }
    }
#endif