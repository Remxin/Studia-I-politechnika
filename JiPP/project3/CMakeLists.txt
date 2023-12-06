cmake_minimum_required(VERSION 3.26)
project(project3 C)

set(CMAKE_C_STANDARD 11)

add_executable(project3
        main.c
        error.c
        io.c
        memory.c
        operations.c)
