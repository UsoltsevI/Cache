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

void move_to_head(List* list, Node* new_head);

void delete_list(List* list);

Node* add_to_head(List* list, TListValue val);

void list_dump (List* list);

Node* get_head(List* list);

Node* get_tail(List* list);

TListValue get_value(Node* node);

#endif // LIST_H