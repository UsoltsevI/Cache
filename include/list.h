#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include "cache.h"

typedef TCacheValue TListValue;

struct node;

struct list;

typedef struct list List;

typedef struct node Node;

List* create_list(size_t size);

void list_move_to_head(List* list, Node* new_head);

void delete_list(List* list);

Node* list_add_to_head(List* list, TListValue val);

void list_dump (List* list);

Node* list_get_head(List* list);

Node* list_get_tail(List* list);

void list_clean(List* list);

void list_set_value (Node* node, TListValue value);

TListValue list_get_value(Node* node);

#endif // LIST_H