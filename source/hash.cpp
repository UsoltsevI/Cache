#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "../include/hash.h"

static size_t get_hash(node* node, table* table);

static void print_table(table* tbl);

static void print_list(t_list* lst);

static void delete_last(t_list* list);

static void push_node(t_list* list, node* node);

struct node
{
    int value;
    node* next;
};

struct t_list
{
    node* head;
    node* end;
    int size;
};

struct table
{
    node** cells;
    t_list* list;
    int size;
};

int main()
{
    printf("govno ");

    table* tb = NULL;
    node* cur = NULL;

    printf("0 ");

    tb = create_table(10);

    printf("1 ");

//     tb->list.head->value = 0;
//     cur = tb->list.head;
//     add_value(tb, cur);
//
//     printf("2 ");
//
//     for(int i = 1; i < 5; i++)
//     {
//         cur = cur->next;
//         cur->value = i;
//         add_value(tb, cur);
//
//         printf("%d ", i + 2);
//     }
//
//     print_table(tb);
//
//     printf("8 ");
//
//     delete_table(tb);
//
//     printf("9 ");

}

table* create_table(int size)
{
    node* cur = NULL;
    table* tbl = NULL;

    tbl = (table*)calloc(1, sizeof(table));
    tbl->list = (t_list*)calloc(1, sizeof(t_list));

    tbl->size = size;
    tbl->list->size = size;

    tbl->cells = (node **) calloc(size, sizeof(node*));

    cur = tbl->list->head;

    for (int i = 0; i < size - 1; ++i) {
        cur->next = (node *) calloc(1, sizeof(node));
        cur = cur->next;
    }
    tbl->list->end = cur;
    return tbl;
}


size_t get_hash(node* nd, table* tbl)
{
    const double a = 0.6180339887;
    size_t pos = 0;

    pos = (int)floor(tbl->size * ((a * (nd->value)) - (int)((a * (nd->value)))));
    return pos;
}


void delete_table(struct table* tbl) {
    struct node* cur = tbl->list->head;

    while (cur->next != tbl->list->end) {
        free(cur);
        cur = cur->next;
    }

    free(cur);

    free(tbl->cells);
}


void add_value(table* tbl, node* nd)
{
    size_t position = 0;
    position = get_hash(nd, tbl);

    tbl->cells[position] = nd;
}

node* delete_cell(table* tbl, int value)
{
    size_t pos = 0;
    node* ptr = NULL;

    node nd;
    nd.value = value;
    nd.next = NULL;

    pos = get_hash(&nd, tbl);
    if (tbl->cells[pos] == NULL)
        return NULL;

    ptr = tbl->cells[pos];
    tbl->cells[pos] = NULL;
    return ptr;
}


void print_list(t_list* lst) {
    node* cur = lst->head;
    size_t i = 0;

    while (i < lst->size + 2 && cur->next != lst->head) {
        printf("%p %i (next->%p)\n", cur, cur->value, cur->next);
        cur = cur->next;
        ++i;
    }

    printf("%p %i (next->%p)\n", cur, cur->value, cur->next);
}

void print_table(table* tbl) {
    printf("LIST:\n");
    print_list(tbl->list);

    printf("ARRAY:\n");
    for (size_t i = 0; i < tbl->size; ++i) {
        printf("%lu %p\n", i, tbl->cells[i]);
    }

    printf("\n");
}


void push_node(t_list* list, node* nd)
{
    node* nxt = NULL;
    nxt = list->head;
    list->head = nd;
    nd->next = nxt;
    list->size += 1;
}

void delete_last(t_list* list)
{
    node* cur = NULL;
    if (list->head == NULL)
        return;
    else
    {
        cur = list->head;
        while(cur->next != list->end)
            cur = cur->next;
        list->end->value = 0;
        list->end = cur;
        cur->next = NULL;
        list->size -= 1;
    }
}
