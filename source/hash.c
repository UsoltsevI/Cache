#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include <stddef.h>
#include "../include/hash.h"
#include "../include/list.h"

// сначала определяем структуры - потом функции +
typedef struct _hashnode t_node;
struct _hashnode {
    THashContent cont;
    THashValue value;
    t_node* next;
}; // == table node сразe используем typedef +

struct table {
    t_node** cells;
    t_node* accumulating_list;
    size_t size;
};

// заменяем на static size_t get_hash(TMap* table, THashValue value) +
static size_t get_hash(TMap* table, THashValue value);

// заменяем на static void print_chain(t_node head); +
static void print_chain(t_node head);

// убираем эту фкнцию +
// static void delete_last(t_list* list);

// добавляем функцию static void delete_chain(t_node* head); +
static void delete_chain(t_node* head);

// заменяем на static void push_node(t_node* head, t_node* node); +
static void push_node(t_node* head, t_node* node);

TMap* create_table(size_t size) {
    t_node* cur = NULL;
    TMap* tbl = NULL;

    tbl = (TMap *) calloc(1, sizeof(TMap));
    tbl->size = size;

    tbl->cells = (t_node**) calloc(size, sizeof(t_node*));

    tbl->accumulating_list = (t_node *) calloc(1, sizeof(t_node));

    cur = tbl->accumulating_list;

    for (size_t i = 0; i < size - 1; ++i) {
        cur->next = (t_node *) calloc(1, sizeof(t_node*));
        cur = cur->next;
    }

    return tbl;
}

// заменяем на static size_t get_hash(TMap* table, THashValue value) +
static size_t get_hash(TMap* table, THashValue value) {
    // можно использовать алгоритм проще: return value % table->size;
    const double a = 0.6180339887;
    size_t pos = 0;

    pos = (int)table->size * ((a * (value)) - (int)((a * (value))));
    return pos;
}

 static void delete_chain(t_node* head) {
     t_node* tofree;

     while (head != NULL) {
         tofree = head;
         head = head->next;
         free(tofree);
     }
 }

void delete_table(TMap* tbl) {
    // Desctuctor по-другому надо написать... +
    // Вот так вот: +
     for (size_t i = 0; i < tbl->size; ++i) {
         delete_chain(tbl->cells[i]);
     }
     free(tbl->cells);
     free(tbl->accumulating_list);
     free(tbl); // ничего лишнего
}

// сигнатура:
// void add_value(TMap* table, THashContent cont, THashValue value); +
void add_value(TMap* table, THashContent cont, THashValue value) {

    size_t position = get_hash(table, value);

    t_node* old_head = table->cells[position]; // сохраняем старую голову
    table->cells[position] = table->accumulating_list; // добавляем перед ней новую ноду
    table->accumulating_list = table->accumulating_list->next; // сдвигаем голову накопительного листа
    table->cells[position]->next = old_head;  // привязываем старую голову к новой ноде
    table->cells[position]->cont = cont;
    table->cells[position]->cont = value;

}

// аналогично add_value, только наоборот
THashContent delete_cell(TMap* table, THashValue value) {
    size_t position = get_hash(table, value);
    t_node* cur = NULL;
    t_node* prev = NULL;
    THashContent save = NULL;

    cur = table->cells[position];

    while(cur != NULL) {
        if ((cur->value == value) && (prev != NULL)) {
            prev->next = cur->next;
            save = cur->cont;
            cur->cont = NULL;
            cur->value = 0;
            cur->next = table->accumulating_list;
            table->accumulating_list = cur;
            printf("delete success\nvalue: %lu/n", value);
            return save;
        }
        else if ((cur->value == value) && (prev == NULL)) {
            save = cur->cont;
            table->cells[position] = cur->next;
            cur->cont = NULL;
            cur->value = 0;
            cur->next = table->accumulating_list;
            table->accumulating_list = cur;
            printf("delete success\nvalue: %lu/n", value);
            return save;
        }
        prev = cur;
        cur = cur->next;
    }
    return NULL;
}


// аналогично delete
THashContent search_cell(TMap* table, THashValue value) {
    size_t position = get_hash(table, value);
    t_node* cur = table->cells[position];
    while(cur != NULL) {
        if (cur->value == value) {
            printf("search success\nvalue: %lu/n", value);
            return cur->cont;
        }
        cur = cur->next;
    }
    return NULL;
}

// эта функция уже не будет работать, придйтся переписать
// потому что у тебя теперь нет бесполезной структуры list
static void print_hash_list(t_node* head) {
    t_node* cur = head;
    while(cur != NULL) {
        printf("|| value: %lu ",cur->value);
        cur = cur->next;
    }
    printf("||\n");
}

// Тоже не будет работать, смотри устройство хэша, я его объяснял
void print_hash_table(const TMap* table) {
    printf("table size: %lu\n", table->size);
    for(int i = 0; i < table->size; ++i) {
        printf("//////////////////////////////\n");
        printf("cell number %i\n", i);
        print_hash_list(table->cells[i]);
        printf("//////////////////////////////\n");
    }
}
