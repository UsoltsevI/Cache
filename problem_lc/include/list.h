#ifndef LIST_H
#define LIST_H
#include <stddef.h>

struct node;

struct list;

typedef struct list List;

typedef struct node Node;

List* create_list_LRU(size_t number_of_elements);

void move_to_head_LRU(List* list, Node* new_head);

void delete_list_LRU(List* list);

Node* add_to_head_LRU(List* list, int val);

void list_dump_LRU(List* list);

Node* get_head_LRU(List* list);

Node* get_tail_LRU(List* list);

int get_value_LRU(Node* node);

#endif // LIST_H