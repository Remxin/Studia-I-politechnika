#include <string.h>
#include <stdio.h>
#include <process.h>
#include <malloc.h>

#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd;

int inputInt(char *text) {
    printf("%s", text);
    int num;
    if (!scanf("%d", &num)) {
        printf("Blad w pobieraniu wartosci");
    };
    return num;
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

void swapLines(int nrskad, int nrdo, char *tab[]) {
    char *bufor = tab[nrskad];
    tab[nrskad] = tab[nrdo];
    tab[nrdo] = bufor;
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

    int nrskad = inputInt("Z ktorej lini zmienic tekst: ");
    int nrdo = inputInt("Do ktorej lini zmienic tekst: ");

    if (nrskad < 0 || nrskad >= i || nrdo < 0 || nrdo >= i) {
        printf("nr musi byc wiekszy od zera i mniejszy od dlugosci pliku");
    }

    swapLines(nrskad, nrdo, d);
    writeToFile(d, i, argv[1]);



}
