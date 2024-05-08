# Cache project

## Description

### Common
This is a school project to implement cache functions. This project implements a cache function that works on the [LRU-K](/documents/Eng_LRU_K.pdf) principle. Also in this project there is a regular LRU algorithm in the folder [/problem_lc](/problem_lc). 
Testing functions are also written. The first is to check the correctness of the program. The second one is for comparison with other caching algorithms, in particular with the usual LRU.

The main cache function returns 0 if miss and 1 if hit. It is also possible to receive information about which page to close. See a more detailed description in [/include/cache.h](/include/cache.h). You can also customize typedef to suit your needs, changing it only in cache.h.


### Algorithm
The main idea of the LRU-K algorithm is that it records the history (time of the last K hits) for each open page. And when it becomes necessary to open some new page, It closes the one where the Kth appeal was the earliest.

### Implementation
The figure below shows an example of dependencies inside the cache function in our implementation:

![structure](/documents/Illust.png)

And the cache_version2 has the following structure:

![structure](/documents/Illust3.png)

The [hash table](https://en.wikipedia.org/wiki/Hash_table) is implemented by the chaining method. A [red-black tree](https://en.wikipedia.org/wiki/Red–black_tree) is also used to quickly find the smallest element. Red-black tree is selected because inserts and deletes are needed much more often in this algorithm than searches.

### Complexity
The difficulty of searching a page due to the hash table is O(1). Adding a change to the list is also O(1). But adding and removing an element in the tree works in O(log(m)), where m is the number of open pages. You have to add and remove elements in the tree every time, because it is a search tree. In total, the complexity of cache LRU-K is O(log(m)).

LRU, unlike LRU-K, works in O(1) because you don't have to look for the smallest element every time. This item will always be the end of the list.

## Usage
To install this repository tap in your console:
```
$ git clone git@github.com:UsoltsevI/Cache.git
```

To create the necessary dependencies:
```
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
```

To create the project library itself and executable files:
```
$ VERBOSE=1 cmake --build ./build
```
The library will be called `liblruk` and will be located in the build folder
The library for a regular LRU will be called `liblrulib` and will be located in the build/problem_lc folder

## Test results
The section will be finalized later...

## Cache functions description
Turn CACHE_PAGE_LINKS_ON on in order to receive information about the page that should be closed.

Included files:
* <stdio.h>

Typedefs:
```
typedef size_t TCacheValue;
typedef size_t TCacheTime;

typedef struct cache TCache;
typedef struct history THist;
```

Functions:
```
// constructor
// size == number of stored pages
struct cache* create_cache(size_t size, size_t k);

// updates cache, adds a link to the 
// page to be closed to to_close
// returns 0 if miss, returns 1 if hit
int cache(struct cache* cch
            , const TCacheValue page
            , TCacheTime time
#ifdef CACHE_PAGE_LINKS_ON
            , TCacheValue* to_close
#endif
            );

// destructor
void delete_cache(struct cache* cch);
```

## Useful links
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
