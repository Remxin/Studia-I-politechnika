# cmake_minimum_required(VERSION 3.26)
project(project2 C)

#set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_EXTENSIONS OFF)


add_executable(project2
        main.c
        io.c
        error.c
        operations.c)
