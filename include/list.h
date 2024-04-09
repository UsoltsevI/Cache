#ifndef LIST_H
#define LIST_H

struct node;

struct list;

typedef struct list List;

typedef struct node Node;

List* create_list(size_t number_of_elements);

void move_to_head (List* list, int val);

void delete_list(List* list);

Node* add_to_list(List* list, int val);

void list_dump (List* list);

Node* get_head(List* list);

#endif // LIST_H