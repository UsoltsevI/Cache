#------------------------------------------------------------------------------
#
# CMake build system for cache LRU algorithm
#
#------------------------------------------------------------------------------

# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
# VERBOSE=1 cmake --build ./build

cmake_minimum_required(VERSION 3.11)
project("cache")

SET(SRCS 
    source/cache.c
    source/hash.c
    source/list.c
)

add_library(lrulib STATIC ${SRCS})
target_include_directories(lrulib PUBLIC "include")

add_executable(lru.x LCmain.c)
target_link_libraries(lru.x PUBLIC lrulib)
