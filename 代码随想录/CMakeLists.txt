cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        "src/Array/Binary search.cpp"
)

add_executable(learn ${SOURCES})
