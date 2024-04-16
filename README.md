# Cache project

## Brief description:
This is a school project to implement cache functions.

The section will be finalized later...

## Usage:
To install this repository tap in your console:
```
$ git clone git@github.com:UsoltsevI/Cache.git
```

The section will be finalized later...

## Functions description:
### Tree:
Included files:
* <stdio.h>
* <stdlib.h>
* ["/include/list.h"](/include/list.h)

Typedefs:
```
typedef List* TTreeContent;
typedef size_t TTreeValue;
typedef struct tree Tree;
```

Structures:
```
struct tree;
```

Functions:
```
// creates tree with specified size and returns link to it
struct list* create_tree(size_t size);

// adds element with content cont sorting by value
void tree_add_value(Tree* tree, TTreeContent cont, TTreeValue value);

// deletes the node with the minimum value
// returns a link to the content
// NULL if not found
TTreeContent tree_delete_min(Tree* tree);

TTreeContent tree_delete_max(Tree* tree);

void delete_tree(Tree* tree);
```


## Useful links:
* [Cache replacement policies](https://en.wikipedia.org/wiki/Cache_replacement_policies)
* [Hash table](https://en.wikipedia.org/wiki/Hash_table)
* [Linked list](https://en.wikipedia.org/wiki/Linked_list)
* [Cache_(computing)](https://en.wikipedia.org/wiki/Cache_(computing))
* [Full Stack Development](https://roadmap.sh/full-stack)
* [How to write README.md](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
* [Eng_LRU_K](/documents/Eng_LRU_K.pdf)

In Russian:
* [Алгоритмы кэширования](https://ru.wikipedia.org/wiki/Алгоритмы_кэширования)
* [Хэш-таблица](https://ru.wikipedia.org/wiki/Хеш-таблица)
* [Связный список](https://ru.wikipedia.org/wiki/Связный_список)
* [Кэш](https://ru.wikipedia.org/wiki/Кэш)
* [Rus_LRU_K](/documents/Rus_LRU_K.pdf)
