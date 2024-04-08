# Cache project

## Cache functions:
```
int cache(struct table* tbl, int value) // adds value to cache and returns 1 if hit, 0 if miss
```

## List functions:
```
struct list* create_list(size_t number_of_elements) // creates list with specified size and returns link to it

void move_to_head(struct list* lst, struct node* nd) // move node from it's porition to list's head

struct node* add_to_head(int value) // adds value to list's head and returns link to head

struct node* get_head(struct list* list) // returns link to head

void delete_list(struct list* list)
```

## Hashmap functions:
```
struct table* create_table(size_t size) // creates list with specified size and returns link to it

void add_value(struct table* table, int value, struct node* nd) // adds node with value (key == value)

void delete_table(struct table* table)
```