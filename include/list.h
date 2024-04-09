#ifndef LIST_H
#define LIT_H

#include "stdlib.h"

typedef struct list List;
typedef struct node Node;

struct node 
{
    struct node* next;
    struct node* prev; 
    size_t val;
};

struct list 
{
    struct node* head;
    struct node* tail;
    size_t size;
};

List* create_list(size_t number_of_elements);

void move_to_head (List* list, int val);

void delete_list(List* list);

Node* add_to_list(List* list, int val);

void list_dump (List* list);

// Node* get_head(List* list);

#endif // LIST_H