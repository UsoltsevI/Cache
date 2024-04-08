# Cache project

## Brief description:
This is a school project to implement cache functions. In the last implementation it uses [a doubly linked lsit](https://en.wikipedia.org/wiki/Doubly_linked_list) and a hash table with a separate chaining collision resolution (see [hash table](https://en.wikipedia.org/wiki/Hash_table)).

## Usage 
To install this repository tap in your console:
```
$ git clone git@github.com:UsoltsevI/Cache.git
```

The [tests](/tests) folder contatins testing program for hashtable and for linked list. Also, there are may be some folders with testing data. 

The section will be finalized later...
### Cache functions:
```
// adds value to cache and returns 1 if hit, 0 if miss
int cache(struct table* tbl, int value) 
```

### List functions:
```
// creates list with specified size and returns link to it
struct list* create_list(size_t number_of_elements);

// move node from it's porition to list's head
void move_to_head(struct list* lst, struct node* nd);

// adds value to list's head and returns link to head
struct node* add_to_head(struct list* lst, int value);

// returns link to head
struct node* get_head(struct list* lst);

void delete_list(struct list* lst);
```

### Hashmap functions:
```
// creates a list with specified size and returns the link to it
struct table* create_table(size_t size);

// adds node with value (key == value)
void add_value(struct table* tbl, int value, struct node* nd);

// removes the cell (from local linked list)
// with value == value,
// but not removes the public linked list's node.
// returns link to removed node (belonging to public linked list, 
// not to local linked list), 
// and NULL if there is no cell with such value
struct node* delete_cell(struct table* tbl, int value);

void delete_table(struct table* tbl);
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
