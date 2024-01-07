cmake_minimum_required(VERSION 3.26)
project(project4 C)

set(CMAKE_C_STANDARD 11)

add_executable(project4
        main.c
        LIFO.c
        menu.c
        error.c
        io.c
        memory.c
        FIFO.c
)
