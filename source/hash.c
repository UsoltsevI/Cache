#include <stdio.h>
#include <malloc.h>
#include <math.h>

static size_t get_hash(node* node, table* table);

static void print_table(const table* tbl);
static void print_list(const t_list* lst);

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
    t_list list;
    int size;
};


table* create_table(int size)
{
    node* cur = NULL;
    table* tbl = NULL;

    tbl->size = size;
    tbl->list.size = size;

    tbl->cells = (node **) calloc(tbl->size, sizeof(node*));

    cur = tbl->list.head = (node *) calloc(1, sizeof(node*));

    for (size_t i = 0; i < size - 1; ++i) {
        cur->next = (node *) calloc(1, sizeof(node*));
        cur = cur->next;
    }
    tbl->list.end = cur;
    return tbl;
}


static size_t get_hash(node* node, table* table)
{
    const float a = 0.6180339887;
    size_t pos = 0;

    pos = floor((*table).size * ((a * (node->value)) - (int)((a * (node->value)))));
    return pos;
}


void delete_table(struct table* tbl) {
    struct node* cur = tbl->list.head;

    while (cur->next != tbl->list.end) {
        free(cur);
        cur = cur->next;
    }

    free(cur);

    free(tbl->cells);
}


void add_value(table* table, node* node)
{
    size_t position = 0;
    position = get_hash(node, table);

    (*table).cells[position] = node;
}

node* delete_cell(table* table, int value)
{
    size_t pos = 0;
    node* ptr = NULL;

    node nd;
    nd.value = value;
    nd.next = NULL;

    pos = get_hash(&nd, table);
    if (table->cells[pos] == NULL)
        return NULL;

    ptr = table->cells[pos];
    table->cells[pos] = NULL;
    return ptr;
}


static void print_list(const t_list* lst) {
    node* cur = lst->head;
    size_t i = 0;

    while (i < lst->size + 2 && cur->next != lst->head) {
        printf("%p %i (next->%p)\n", cur, cur->value, cur->next);
        cur = cur->next;
        ++i;
    }

    printf("%p %i (next->%p)\n", cur, cur->value, cur->next);
}


static void print_table(const table* tbl) {
    printf("LIST:\n");
    print_list(&tbl->list);

    printf("ARRAY:\n");
    for (size_t i = 0; i < tbl->size; ++i) {
        printf("%lu %p\n", i, tbl->cells[i]);
    }

    printf("\n");
}


static void push_node(t_list* list, node* node)
{
    node* nxt = NULL;
    nxt = list->head;
    list->head = node;
    node->next = nxt;
    list->size += 1;
}


static void delete_last(t_list* list)
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


//int main()
//{
//    table* tb = NULL;
//    node* cur = NULL;
//
//    tb = create_table(10);
//
//    tb->list.head->value = 0;
//    cur = tb->list.head;
//    add_value(tb, cur);
//
//    for(int i = 1; i < 5; i++)
//    {
//        cur = cur->next;
//        cur->value = i;
//        add_value(tb, cur);
//    }
//
//    print_table(tb);
//
//    delete_table(tb);
//
//}
//
