#include <string.h>
#include <stdio.h>
#include <process.h>
#include <malloc.h>

#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;

char *inputString(char *text, char *str) {
    printf("%s", text);
    fgets(str, MAX_LINE, stdin);
    return &str;
}

void writeToFile(char **content, int tablen, char *filename) {
    if (!(fd = fopen(filename, "w"))) {
        printf("nie udalo sie otworzyc pliku do zapisu");
        return;
    }
    for (int i = 0; i < tablen; i++) {
        fprintf(fd, "%s\n", content[i]);
    }

}

void search(char **content, int n, char *szukane) {
    for (int i = 0; i < n; i++ ) {
        int done = 1;

        for (int j = 0; j < strlen(szukane) - 1; j++) {
            if (szukane[j] != content[i][j]) {

                done = 0;
                break;
            }
        }
        if (done == 1) {
            printf("Znaleziono w linii %d: ", i);
            exit(0);
        }
    }
    printf("nie znaleziono ciagu znakow");
    exit(1);
}

int main(int argc, char **argv){

    char *d[MAX_LINES], bufor[MAX_LINE];
    int len, i, l;
    if (argc != 2)
    {
        printf("Zła liczba argumentów\n");
        exit(1);
    }
    if (!(fd = fopen(argv[1], "r")))
    {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }

    i = 0;
    l = 0;
    while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
    {
        len = strlen(bufor);
        bufor[len - 1] = '\0';
        if (!(d[i] = (char*)malloc((unsigned)len)))
        {
            printf("Brak pamieci\n");
            exit(3);
        }
        strcpy(d[i], bufor);

        i++;
    }
    d[i] = (char *)0;
    fclose(fd);
    fd = NULL;
    char szukane[MAX_LINE];
    inputString("Podaj szukany ciag znakow: ", szukane);

    search(d, i, szukane);



}
