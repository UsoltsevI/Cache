#include "stdio.h"
#include "stdlib.h"

#include "../include/list.h"

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


List* create_list (size_t number_of_elements)
{
    List* list = (List*)calloc(1, sizeof(List));

    list->size = number_of_elements;

    list->head = (Node*)calloc(1, sizeof(Node));
    Node* list_temp = list->head;

    for (int i = 0; i < number_of_elements - 1; i++)
    {
        list_temp->next = (Node*)calloc(1, sizeof(Node));
        list_temp->next->prev = list_temp;

        list_temp = list_temp->next;  
    }
    list->tail = list_temp;
    
    list->tail->next = list->head;
    list->head->prev = list->tail;

    return list;
}

void delete_list (List* list)
{
    Node* list_temp = list->head;

    for (int i = 0; i < list->size - 1; i++)
    {
        list_temp = list_temp->next;
        free(list_temp->prev);
    }
    free(list_temp);
    free(list);
}

void move_to_head (List* list, Node* new_head)
{
    if (new_head == NULL)
        return;
    
    if (new_head == list->head)
        return;
    
    if (new_head == list->tail)
    {
        list->head = new_head;
        list->tail = new_head->prev;
        return;
    }

    new_head->prev->next = new_head->next;

    list->head->prev = new_head;
    new_head->next = list->head;
    new_head->prev = list->tail;

    list->tail->next = new_head;

    list->head = new_head;
}

Node* add_to_list(List* list, int val)
{
    Node* list_temp = list->head;

    for (int i = 0; i < list->size; i++)
    {
        if (list_temp->val == 0)
        {
            list_temp->val = val;
            return list_temp;
        }
        list_temp = list_temp->next;
    }
    list_temp = list_temp->prev;

    list_temp->val = val;
    list->head = list_temp;
    list->tail = list_temp->prev;

    return list_temp;
}

Node* get_head (List* list)
{
    return list->head;
}

void list_dump (List* list)
{
    Node* list_temp = list->head;

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ->", list_temp->val);
        list_temp = list_temp->next;
    }
    printf("NULL\n");
}