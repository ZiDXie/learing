cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        src/Array/BinarySearch.cpp
        src/Array/RemoveNums.cpp
        src/Array/SortedSquared.cpp
        ../../../../../../tmp/leetcode/editor/cn/[977]有序数组的平方.cpp
)

add_executable(learn ${SOURCES})

