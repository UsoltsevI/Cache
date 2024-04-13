#ifndef HASH_H
#define HASH_H

#include <stddef.h>
#include <stdlib.h>

typedef struct list* THashContent; // == Hash Content Type
//struct list; // included from list.h

typedef size_t THashValue; // == Hash Value Type. Ну то есть то, по чему мы ищем значение в content

typedef struct table TMap; // == Hash Map Type
struct table; // main struct defenition

// creates a list with specified size and returns the link to it
TMap* create_table(size_t size);

void delete_table(TMap* table);

// adds node with value (key == value)
void add_value(TMap* table, THashContent cont, THashValue value);

// find cell with value
THashContent search_cell(TMap* table, THashValue value);

// removes the cell (from local linked list)
// with value == value,
// but not removes the public linked list's node.
// returns link to removed node (belonging to public linked list,
// not to local linked list),
// and NULL if there is no cell with such value
THashContent delete_cell(TMap* table, THashValue value);

void print_hash_table(const TMap* tbl);

#endif
