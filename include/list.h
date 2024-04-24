#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include "cache.h"

struct node;

struct list;

typedef struct list List;

typedef struct node Node;

List* create_list(size_t size);

void list_move_to_head(List* list, Node* new_head);

void delete_list(List* list);

Node* list_add_to_head(List* list);

void list_dump (List* list);

Node* list_get_head(List* list);

Node* list_get_tail(List* list);

void list_clean(List* list);

#endif // LIST_H