project(project2-wc C)

set(CMAKE_C_STANDARD 11)

add_executable(project2
        main.c
        io.c
        memory.c
        error.c
        operations.c)
