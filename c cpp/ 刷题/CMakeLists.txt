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
        src/LinkList/reverseList.cpp
        src/LinkList/swapPairs.cpp
        src/LinkList/removeNthFromEnd.cpp
        src/LinkList/detectCycle.cpp
        src/Hash/isAnagram.cpp
        src/Hash/intersection.cpp
        src/Hash/twoSum.cpp
        src/Hash/fourSumCount.cpp
        src/Hash/threeSum.cpp
        src/Hash/fourSum.cpp
        src/String/reverseString.cpp
        src/String/reverseStr.cpp
        src/String/reverseWords.cpp
        src/String/kmp.cpp
        src/Stack_Queue/MyQueue.cpp
)

add_executable(learn ${SOURCES})
