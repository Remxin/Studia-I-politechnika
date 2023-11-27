#include <string.h>
#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;

char * trim_space(char *str) {
    char *end;
    /* skip leading whitespace */
    while (isspace(*str)) {
        str = str + 1;
    }
    /* remove trailing whitespace */
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end = end - 1;
    }

    *(end+1) = '\0';
    return str;
}

int inputInt(char *text) {
    printf("%s", text);
    int num;
    if (!scanf("%d", &num)) {
        printf("Blad w pobieraniu wartosci");
    };
    return num;
}

void *inputString(char *text, char *str) {
    printf("%s", text);
    fgets(str, MAX_LINE, stdin);
}

void writeToFile(char content[MAX_LINE][MAX_LINE], int tablen, char *filename) {
    if (!(fd = fopen(filename, "w"))) {
        printf("nie udalo sie otworzyc pliku do zapisu");
        return;
    }
    for (int i = 0; i < tablen; i++) {
        fprintf(fd, "%s\n", trim_space(content[i]));
    }

}

void addLine(char **content, int od, int n, char *ciag) {
    char bufor1[MAX_LINE][MAX_LINE];
    int contentlen = 0;

    for (int i = 0; i < n + 1; i ++) {
        if (i == od + 1) {
            strcpy(bufor1[i], ciag);
            continue;
        }
        strcpy(bufor1[i], content[contentlen]);
        contentlen++;
    }
    writeToFile(bufor1, n+1, "DANE.txt");

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

    char str[MAX_LINE];
    inputString("Ciag znakow do dodania: ", str);
    int nrod = inputInt("Po ktorej lini dodac tekst: ");

    char *ciag = malloc(strlen(str) + 2);
    strcpy(ciag, "\n"); strcat(ciag, str);

    if (nrod < 0 || nrod >= i) {
        printf("nr musi byc wiekszy od zera i mniejszy od dlugosci pliku");
    }

    addLine(d, nrod, i, ciag);

    return 0;

}
