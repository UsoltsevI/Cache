#ifndef LIST_H
#define LIST_H
#include <stddef.h>
#include "cache.h"

typedef THist* TListValue;

struct node;

struct list;

typedef struct list TList;

typedef struct node TNode;

TList* create_list(size_t size);

void list_move_to_head(TList* list, TNode* new_head);

void delete_list(TList* list);

TNode* list_add_to_head(TList* list, TListValue val);

void list_dump (TList* list);

TNode* list_get_head(TList* list);

TNode* list_get_tail(TList* list);

void list_clean(TList* list);

void list_set_value (TNode* node, TListValue value);

TListValue list_get_value(TNode* node);

#endif // LIST_H