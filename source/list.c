#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

struct node {
    struct node* next;
    struct node* prev; 
};

struct list {
    struct node* head;
    struct node* tail;                                              
    struct node* fact_tail;
    size_t size;
};

List* create_list (size_t number_of_elements){
    List* list = (List*) calloc(1, sizeof(List));
    Node* list_temp;

    list->size = number_of_elements;

    list->head = (Node*) calloc(1, sizeof(Node));
    list_temp = list->head;

    for (size_t i = 0; i < number_of_elements - 1; i++) {
        list_temp->next = (Node*) calloc(1, sizeof(Node));
        list_temp->next->prev = list_temp;

        list_temp = list_temp->next;  
    }

    list->tail = list_temp;
    
    list->tail->next = list->head;
    list->head->prev = list->tail;

    list->fact_tail = list->tail;

    return list;
}

void delete_list (List* list) {
    Node* temp = list->head;
    Node* to_free;

    for (size_t i = 0; i < list->size; ++i) {
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
    
    free(list);
}

void list_move_to_head(List* list, Node* new_head) {
    if (new_head == NULL) {
        return;
    }
    
    if (new_head == list->head) {
        return;
    }
    
    if (new_head == list->tail) {
        list->head = new_head;
        list->tail = new_head->prev;
        return;
    }

    if (new_head == list->fact_tail)
        list->fact_tail = new_head->prev;

    new_head->prev->next = new_head->next;
    new_head->next->prev = new_head->prev;

    new_head->next = list->head;
    new_head->prev = list->tail;

    list->head->prev = new_head;
    list->tail->next = new_head;

    list->head = new_head;
}

Node* list_add_to_head(List* list) {
    list->head = list->tail;
    list->tail = list->tail->prev;

    return list->head;
}

Node* list_get_head(List* list) {
    return list->head;
}

Node* list_get_tail(List* list) {
    return list->fact_tail;
}


void list_clean(List* list) {
    Node* temp = list->head;
    Node* to_free;

    for (size_t i = 0; i < list->size; ++i) {
        to_free = temp;
        temp = temp->next;
    }

    list->fact_tail = list->tail;

}

// void list_list_dump(List* list) {
//     Node* list_temp = list->head;

//     for (size_t i = 0; i < list->size; ++i) {  // ×ÒÎ ÏÅ×ÀÒÀÒÜ ÒÎ?
//         list_temp = list_temp->next;
//     }

//     printf("NULL\n");
// }