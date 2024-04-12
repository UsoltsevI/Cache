#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>
#include "../include/hash.h"

// сначала определяем структуры - потом функции +
typedef struct _hashnode {
    THashContent cont;
    THashValue value;
    t_node next;
} t_node; // == table node сразe используем typedef +

struct table {
    t_node** cells;
    t_node* accumulating_list;
    size_t size;
};

// заменяем на static size_t get_hash(TMap* table, THashValue value) +
static size_t get_hash(TMap* table, THashValue value);

// заменяем на static void print_table(const TMap* table); +
static void print_table(const TMap* tbl);

// заменяем на static void print_chain(t_node head); +
static void print_chain(t_node head);

// убираем эту фкнцию +
// static void delete_last(t_list* list);

// добавляем функцию static void delete_chain(t_node* head); +
static void delete_chain(t_node* head);

// заменяем на static void push_node(t_node* head, t_node* node); +
static void push_node(t_node* head, t_node* node);

// перенеси всю функцию main в отдельный файл /tests/test_hash.c и
// и используй раздельную компиляцию для тестирования
int main()
{
    printf("start ");

    table* tb = NULL;
    node* cur = NULL;

    printf("0 ");

    tb = create_table(10);

    printf("1 ");
//// не коммить участки кода!!!
//// При необходимости используй #if 0 ...code... #endif
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

TMap* create_table(size_t size) {
    t_node* cur = NULL;
    TMap* tbl = NULL;

    tbl = (TMap *) calloc(1, sizeof(TMap));
    tbl->size = size;

    tbl->cells = (t_node**) calloc(tbl->size, sizeof(t_node*));

    tbl->accumulating_list = (t_node *) calloc(1, sizeof(t_node));

    cur = tbl->accumulating_list;

    for (size_t i = 0; i < size - 1; ++i) {
        cur->next = (t_node *) calloc(1, sizeof(t_node*));
        cur = cur->next;
    }

    return tbl;
}

// заменяем на static size_t get_hash(TMap* table, THashValue value)
size_t get_hash(node* nd, table* tbl) {
    // можно использовать алгоритм проще: return value % table->size;
    const float a = 0.6180339887;
    size_t pos = 0;

    pos = (int)floor(tbl->size * ((a * (nd->value)) - (int)((a * (nd->value)))));
    return pos;
}

// добавляем такую функцию:
// static void delete_chain(t_node* head) {
//     t_node* tofree;
//
//     while (head != NULL) {
//         tofree = head;
//         head = head->next;
//         free(tofree);
//     }
// }

void delete_table(TMap* tbl) {
    // Desctuctor по-другому надо написать...
    // Вот так вот:
    // for (size_t i = 0; i < tbl->size; ++i) {
    //     delete_chain(tbl->cells[i]);
    // }
    // free(tbl->cells);
    // free(tbl->accumulating_list);
    // free(tbl); // ничего лишнего
    struct node* cur = tbl->list->head;

    while (cur->next != tbl->list->end) {
        free(cur);
        cur = cur->next;
    }

    free(cur);

    free(tbl->cells);
}

// сигнатура:
// void add_value(TMap* table, THashContent cont, THashValue value);
void add_value(table* tbl, node* nd) {
    // вместо нижних двух строк сразу
    // size_t position = get_hash(tbl, value);
    size_t position = 0;
    position = get_hash(nd, tbl);

    // Это не будер работать, потому что так ты теряешь ячейки при коллизии
    tbl->cells[position] = nd;
    // Будет работать вот это:
    // t_node* old_head = tbl->cells[position]; // сохраняем старую голову
    // tbl->cells[position] = tbl->accumulation_list; // добавляем перед ней новую ноду
    // tbl->accumulation_list = tbl->accumulation_list->next; // сдвигаем голову накопительного листа
    // tbl->cells[position]->next = old_head; // привязываем старую голову к новой ноде
}

// аналогично add_value, только наоборот
THashContent delete_cell(table* tbl, int value) {
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

// аналогично delete
THashContent search_cell(TMap* table, THashValue value);


// эта функция уже не будет работать, придйтся переписать
// потому что у тебя теперь нет бесполезной структуры list
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

// Тоже не будет работать, смотри устройство хэша, я его объяснял
void print_table(const table* tbl) {
    printf("LIST:\n");
    print_list(&tbl->list);

    printf("ARRAY:\n");
    for (size_t i = 0; i < tbl->size; ++i) {
        printf("%lu %p\n", i, tbl->cells[i]);
    }

    printf("\n");
}

//написана выше
void push_node(t_list* list, node* nd)
{
    node* nxt = NULL;
    nxt = list->head;
    list->head = nd;
    nd->next = nxt;
    list->size += 1;
}

