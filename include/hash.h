#ifndef HASH_H
#define HASH_H

typedef struct t_list t_list;
struct t_list;

typedef struct node node;
struct node;

typedef struct table table;
struct table;

table* create_table(int size);
void delete_table(table* tbl);

void add_value(table* table, node* value);
node* delete_cell(table* table, int value);

#endif
