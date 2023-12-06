#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
     setlocale(LC_ALL, "pl_PL.UTF-8");
    FILE *fd;
    if (!(fd = fopen("wyniki.txt", "w"))) return -1;
    char *b = "ąźęćłęźć";
    printf("%s", b);
    // for (int i = 0; i < 5; i++) {
    //     char buffor[2];
    //     buffor[0] = b[i];
    //     buffor[1] = b[i+1];
    //     buffor[1] = '\0';
    //     char *test;
    //     // strcpy(test, (char*)b[i]);
    //     printf("%s\n", buffor);
    //     fprintf(fd, "%s\n", buffor);
    //     fprintf(fd, "%s", "ą");
    // }
    fclose(fd);
    fd = NULL;
    return 0;
}