cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        src/Array/BinarySearch.cpp
        src/Array/RemoveNums.cpp
        src/Array/SortedSquared.cpp
        src/Array/minSubArrayLen.cpp
        src/Array/generateMatrix.cpp
        src/LinkList/removeElements.cpp
        src/LinkList/MyLinkedList.cpp
        src/Array/区间和.cpp
)

add_executable(learn ${SOURCES})
