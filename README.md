# Cache project

## Description

### Common
This is a school project to implement cache functions. This project implements a cache function that works on the [LRU-K](/documents/Eng_LRU_K.pdf) principle. Also in this project there is a regular LRU algorithm in the folder [/problem_lc](/problem_lc). 
Testing functions are also written. The first is to check the correctness of the program. The second one is for comparison with other caching algorithms, in particular with the usual LRU.

The main cache function returns 0 if miss and 1 if hit. It is also possible to receive information about which page to close. See a more detailed description in [/include/cache.h](/include/cache.h). You can also customize typedef to suit your needs, changing it only in cache.h.

### Algorithm
The main idea of the LRU-K algorithm is that it records the history (time of the last K hits) for each open page. And when it becomes necessary to open some new page, It closes the one where the Kth appeal was the earliest.

In the cache.c implementation, if a page has less than K hits recorded in its history, then the kth hit is counted at minus infinity. And then this page is written not to the tree, but to the linked list. In case of a miss, we first look at the presence of elements in the list and remove the last one from there, if they are not there, then we find the minimum element in the tree and delete it. See the implementation diagram below.

In cache_mod.c implementation, we always look at the last call that is less than or equal to K. In this case, we do not need a linked list.

### Implementation
The figure below shows an example of dependencies inside the cache function in our implementation:

![structure](/documents/Illust3.png)

And the cache_mod has the following structure:

![structure](/documents/Illust.png)

The [hash table](https://en.wikipedia.org/wiki/Hash_table) is implemented by the chaining method. A [red-black tree](https://en.wikipedia.org/wiki/Red–black_tree) is also used to quickly find the smallest element. Red-black tree is selected because inserts and deletes are needed much more often in this algorithm than searches.

### Complexity
The difficulty of searching a page due to the hash table is O(1). Adding a change to the list is also O(1). But adding and removing an element in the tree works in O(log(m)), where m is the number of open pages. You have to add and remove elements in the tree every time, because it is a search tree. In total, the complexity of cache LRU-K is O(log(m)).

LRU, unlike LRU-K, works in O(1) because you don't have to look for the smallest element every time. This item will always be the end of the list.

## Usage
To install this repository tap in your console:
```
git clone git@github.com:UsoltsevI/Cache.git
```

To create the necessary dependencies in build folder:
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
```

To create the project library itself and executable files:
```
VERBOSE=1 cmake --build ./build
```
This command will compile all executable files and libraries into the buildings folder.

The library will be called `liblruk` and will be located in the build folder.
The library for cache_mod will be located there and called `liblrukmod`.
The library for a regular LRU will be called `liblrulib` and will be located in the build/problem_lc folder.

## Test results
The section will be finalized later...

## Useful links
* [Cache replacement policies](https://en.wikipedia.org/wiki/Cache_replacement_policies)
* [Hash table](https://en.wikipedia.org/wiki/Hash_table)
* [Linked list](https://en.wikipedia.org/wiki/Linked_list)
* [Cache_(computing)](https://en.wikipedia.org/wiki/Cache_(computing))
* [Full Stack Development](https://roadmap.sh/full-stack)
* [How to write README.md](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
* [red-black tree](https://en.wikipedia.org/wiki/Red–black_tree) 
* [Eng_LRU_K](/documents/Eng_LRU_K.pdf)

In Russian:
* [Алгоритмы кэширования](https://ru.wikipedia.org/wiki/Алгоритмы_кэширования)
* [Хэш-таблица](https://ru.wikipedia.org/wiki/Хеш-таблица)
* [Связный список](https://ru.wikipedia.org/wiki/Связный_список)
* [Кэш](https://ru.wikipedia.org/wiki/Кэш)
* [Rus_LRU_K](/documents/Rus_LRU_K.pdf)
