#------------------------------------------------------------------------------
#
# CMake build system for cache LRU-K project
#
#------------------------------------------------------------------------------

# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
# VERBOSE=1 cmake --build ./build

cmake_minimum_required(VERSION 3.11)
project("cache")

SET(SRCS
    source/cache.c
    source/hash.c
    source/queue.c
    source/tree.c
    source/list.c
)

add_subdirectory(problem_lc)

add_library(lruk STATIC ${SRCS})
target_include_directories(lruk PUBLIC "include")

add_executable(lruk.x main.c)
target_link_libraries(lruk.x PUBLIC lruk)

# Executable file for comparison with cache_LRU 
# and testing with different K and M
add_executable(cache_compare.x ./tests/cache_compare.c)
target_link_libraries(cache_compare.x PUBLIC lruk lrulib)

# An executable file for creating tests. 
# The responses generated by him will check 
# the cache for the correctness of the algorithm implementation.
add_executable(test_cache.x ./tests/test_cache.c)
target_link_libraries(test_cache.x PUBLIC lruk)

# For LRU-K mod:
# 
# SET(SRCSM
#     source/cache_mod.c
#     source/hash.c
#     source/queue.c
#     source/tree.c
# )
#
# add_library(lrukmod STATIC ${SRCSM})
# target_include_directories(lrukmod PUBLIC "include")
#
# add_executable(lrukmod.x main.c)
# target_link_libraries(lrukmod.x PUBLIC lrukmod)
#
# add_executable(cache_compare.x ./tests/cache_compare.c)
# target_link_libraries(cache_compare.x PUBLIC lrukmod lrulib)