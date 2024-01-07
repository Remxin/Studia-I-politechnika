project(project2-wc C)

set(CMAKE_C_STANDARD 11)

add_executable(project2
        main.cpp
        io.c
        memory.c
        error.c
        operations.c)
