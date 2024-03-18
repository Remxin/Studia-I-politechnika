#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

extern void error(int nr, char *str);


char *getString(char *text) {
    char buffer[MAX_BUFFER_SIZE];
    printf("%s", text);
    if (scanf("%s", buffer) != 1) error(4, "Wymagany jest typ danych string!");

    buffer[strlen(buffer)] = '\0';
    char *ret = (char *)malloc(sizeof(buffer));
    strcpy(ret, buffer);
    return ret;
}

int getInt(char *text) {
    int num;
    printf("%s", text);
    if (scanf("%d", &num) != 1) error(4, "Wymagany jest typ danych string!");
    return num;
}


