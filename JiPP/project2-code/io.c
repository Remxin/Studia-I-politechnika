#include <stdlib.h>
<<<<<<< HEAD:JiPP/project2-wc/io.c
#include <stdio.h>

#define MAX_STRLEN 1000
=======
#include "header.h"
#include <memory.h>

#define MAX_STRLEN 10000
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716:JiPP/project2-code/io.c
extern void error(int nr, char *str);

FILE *fd = NULL;
FILE *fdin = NULL;

char *InputText(char *text) {
    char *buffer;
    size_t bufsize = MAX_STRLEN;

    if (!(fdin = fopen("dane.txt", "r"))) error(2, "blad otwarcia pliku");

<<<<<<< HEAD:JiPP/project2-wc/io.c
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL) error(3, "blad w przypisywaniu pamieci dla tekstu");
=======

    buffer = (char *)malloc(bufsize * sizeof(char));
    memset(buffer, 0, MAX_STRLEN);
    if (buffer == NULL) error(3, "blad w przypisywaniu pamieci dla tekstu");
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716:JiPP/project2-code/io.c

    printf("%s", text);
    fgets(buffer, MAX_STRLEN, stdin);
    
    return buffer;
}

void InitPlik() {
    if (!(fd = fopen("wyniki.txt", "w"))) error(2, "blad w otwarciu pliku");
    char *b = "ąźćół";
    printf("%s", b);
//    for (int i = 0; i < 1000; i++) {
//        printf("%c", 'ą');
////        fprintf(fd,"%c", i);
////        printf("%c", i);
//    }
}

void ZamknijPlik() {
    fclose(fd);
    fd = NULL;
}

void Pisz(char c) {
    fprintf(fd, "%c", c);
}

void Piszstr(char *str) {
    fprintf(fd, "%s", str);
}