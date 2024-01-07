cmake_minimum_required(VERSION 3.26)
project(project3 C)

set(CMAKE_C_STANDARD 11)

<<<<<<< HEAD:JiPP/project2-wc/CMakeLists.txt
add_executable(project2
        main.cpp
=======
add_executable(project3
        main.c
        error.c
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716:JiPP/project3/CMakeLists.txt
        io.c
        memory.c
        operations.c)
