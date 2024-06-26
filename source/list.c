// ----------------------
//
// this is an implementation of the "list" data structure.
//
// ----------------------

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/list.h"

struct node { // node of the list
    struct node* next;
    struct node* prev; 
    TListValue val;
};

struct list {
    struct node* head; // ptr to head
    struct node* tail; // ptr to tail                                         
    struct node* fact_tail; // ptr to last not empty element of list ( if list is full -> tail = fact_tail )
    size_t size;
    int is_empty; // list emptiness indicator
};

TListValue LISTGARBAGE = NULL;

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

TNode* list_add_to_head(TList* list, TListValue val) {
    list->tail->val = val;
    list->head = list->tail;
    list->tail = list->tail->prev;

    if (list->is_empty) {
        list->fact_tail = list->head;
        list->is_empty = 0;
    }

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

void list_delete_node(TList* list, TNode* node) {
    if (list->is_empty) {
        return;
    }

    if (list->fact_tail == node && list->head == node) {
        list->is_empty = 1;
        list->fact_tail = list->tail;
        return;
    }

    if (node == list->fact_tail) {
        list->fact_tail = list->fact_tail->prev;
        return;
    }

    if (node == list->head) {
        list->head = list->head->next;
        list->tail = list->tail->next;
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->prev = list->fact_tail;
    node->next = list->fact_tail->next;

    list->fact_tail->next->prev = node;
    list->fact_tail->next = node;

    if (list->fact_tail == list->tail) {
        list->tail = list->tail->next;
    }
}

#ifdef CACHE_DEBUGON
    void list_dump(TList* list) {
        TNode* list_temp = list->head;

        for (size_t i = 0; i < list->size; ++i) {
            if (list_temp == list->fact_tail) {
                printf("FACT_TAIL ");
            }
            if (list_temp->val == LISTGARBAGE) {
                printf("(nil) -> ");
            } else {
                printf("(%p, %d) -> ", list_temp->val, hist_get_key(list_temp->val));
            }
            list_temp = list_temp->next;
        }

        printf("NULL\n");
    }
#endif

void list_verificator (TList* list) {
    TNode* node = list->head;
    for (int i = 0; i < list->size; ++i) {
        node = node->next;
    }
    assert(node == list->head);
}