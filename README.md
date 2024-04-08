# Cache project

## Brief description:
The section will be added later...

## Usage 
To install this repository tap in your console:
```
$ git clone git@github.com:UsoltsevI/Cache.git
```
The section will be added later...

### Cache functions:
```
int cache(struct table* tbl, int value) // adds value to cache and returns 1 if hit, 0 if miss
```

### List functions:
```
struct list* create_list(size_t number_of_elements) // creates list with specified size and returns link to it

void move_to_head(struct list* lst, struct node* nd) // move node from it's porition to list's head

struct node* add_to_head(int value) // adds value to list's head and returns link to head

struct node* get_head(struct list* list) // returns link to head

void delete_list(struct list* list)
```

### Hashmap functions:
```
struct table* create_table(size_t size) // creates list with specified size and returns link to it

void add_value(struct table* table, int value, struct node* nd) // adds node with value (key == value)

void delete_table(struct table* table)
```

## Useful links:
* [Cache replacement policies](https://en.wikipedia.org/wiki/Cache_replacement_policies)
* [Hash table](https://en.wikipedia.org/wiki/Hash_table)
* [Linked list](https://en.wikipedia.org/wiki/Linked_list)
* [Cache_(computing)](https://en.wikipedia.org/wiki/Cache_(computing))
* [How to write README.md](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

In Russian:
* [Алгоритмы кэширования](https://ru.wikipedia.org/wiki/Алгоритмы_кэширования)
* [Хэш-таблица](https://ru.wikipedia.org/wiki/Хеш-таблица)
* [Связный список](https://ru.wikipedia.org/wiki/Связный_список)
* [Кэш](https://ru.wikipedia.org/wiki/Кэш)
