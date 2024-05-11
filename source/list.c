#include <stdio.h>
#include <stdlib.h>

#include "../include/list.h"

struct node {
    struct node* next;
    struct node* prev; 
    TListValue val;
};

struct list {
    struct node* head;
    struct node* tail;                                              
    struct node* fact_tail;
    size_t size;
    int is_empty;
};

const int LISTGARBAGE = -1;

TList* create_list (size_t number_of_elements){
    TList* list = (TList*) calloc(1, sizeof(TList));
    TNode* list_temp;

    list->size = number_of_elements;

    list->head = (TNode*) calloc(1, sizeof(TNode));
    list_temp = list->head;
    list_temp->val = LISTGARBAGE;

    for (size_t i = 0; i < number_of_elements - 1; i++) {
        list_temp->next = (TNode*) calloc(1, sizeof(TNode));
        list_temp->next->val = LISTGARBAGE;
        list_temp->next->prev = list_temp;

        list_temp = list_temp->next;  
    }

    list->tail = list_temp;
    
    list->tail->next = list->head;
    list->head->prev = list->tail;

    list->fact_tail = list->tail;

    list->is_empty = 1;

    return list;
}

void delete_list (TList* list) {
    TNode* temp = list->head;
    TNode* to_free;

    for (size_t i = 0; i < list->size; ++i) {
        to_free = temp;
        temp = temp->next;
        free(to_free);
    }
    
    free(list);
}

void list_move_to_head(TList* list, TNode* new_head) {
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

TNode* list_add_to_head(TList* list, TListValue val) {
    list->is_empty = 0;

    list->tail->val = val;
    list->head = list->tail;
    list->tail = list->tail->prev;

    return list->head;
}

TNode* list_get_head(TList* list) {
    if (list->is_empty) {
        return NULL;
    }
    return list->head;
}

TNode* list_get_tail(TList* list) {
    return list->fact_tail;
}

TListValue list_get_value(TNode* node) {
    return node->val;
}

void list_set_value (TNode* node, TListValue value) {
    node->val = value;
}

void list_clean(TList* list) {
    TNode* temp = list->head;
    TNode* to_free;

    for (size_t i = 0; i < list->size; ++i) {
        to_free = temp;
        temp = temp->next;
        to_free->val = LISTGARBAGE;
    }

    list->fact_tail = list->tail;
    list->is_empty = 1;
}

void list_dump(TList* list) {
    TNode* list_temp = list->head;

    for (size_t i = 0; i < list->size; ++i) {
        printf("%ld ->", list_temp->val);
        list_temp = list_temp->next;
    }

    printf("NULL\n");
}