# 
# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
# VERBOSE=1 cmake --build ./build
cmake_minimum_required(VERSION 3.11)
project("cache")

SET(SRCS 
    source/cache.c
    source/hash.c
    source/list.c
    source/tree.c
)

add_library(lruklib STATIC ${SRCS})
target_include_directories(lruklib PUBLIC "include")

add_executable(lruk.x main.c)
target_link_libraries(lruklib)
