# Cache project

## Brief description:
This is a school project to implement cache functions. This project implements a cache function that works on the [LRU-K](/documents/Eng_LRU_K.pdf) principle. Also in this project there is a regular LRU algorithm in the folder [/problem_lc](/problem_lc). 
Testing functions are also written. The first is to check the correctness of the program. The second one is for comparison with other caching algorithms, in particular with the usual LRU.

The main cache function returns 0 if miss and 1 if hit. It is also possible to receive information about which page to close. See a more detailed description in [/include/cache.h](/include/cache.h).

## Usage:
To install this repository tap in your console:
```
$ git clone git@github.com:UsoltsevI/Cache.git
```
To create cache LRU-K library:
```
// The section will be finalized later...
```
## Test results:
The section will be finalized later...

## Functions description:

### Cache:
Turn CACHE_PAGE_LINKS_ON on in order to receive information about the page that should be closed.

Included files:
* <stddef.h>
* <stdio.h>
* <stdlib.h>
* "../include/cache.h"
* "../include/list.h"
* "../include/hash.h"
* "../include/tree.h"

Typedefs:
```
typedef size_t TCacheValue;
typedef size_t TCacheTime;
```

Structures:
```
struct cache;
```

Functions:
```
// constructor
// size == number of stored pages
struct cache* create_cache(size_t size, size_t k);

// updates cache
// adds a link to the page to be closed to to_close
// returns 0 if miss
// returns 1 if hit
int cache(struct cache* cch
            , const TCacheValue* page
            , TCacheTime time
#ifdef CACHE_PAGE_LINKS_ON
            , TCacheValue* to_close
#endif
            );

// destructor
void delete_cache(struct cache* cch);
```

### Tree:
Included files:
* <stdio.h>
* <stdlib.h>
* ["/include/cache.h"](/include/list.h)

Typedefs:
```
typedef List* TTreeContent;
typedef size_t TTreeValue;
typedef struct tree TTree;
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
