cmake_minimum_required(VERSION 3.30)
project(lab3LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3LinkedList src/main.cpp
        include/element.h
        include/linkedList.h
        include/tests.h
        include/badTests.h
)
