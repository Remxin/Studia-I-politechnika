//Liczba słów w wielu liniach tekstu (1) - tablice o dwóch indeksach
#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256
#define MAX_LINES 200
FILE *fd = NULL;


int wstawLinie(char *d[], int n) {
    int i = 0;
    char buffor[MAX_LINE];
    while (i < MAX_LINES && fgets(d[i], MAX_LINE, fd) != (char*)NULL)
    {
        if (i < n - 1) continue;
        strcpy(d[i], buffor);
        strcpy();
        i++;
    }
    return 0;
}

int main()
{
    char d[MAX_LINES][MAX_LINE];
    int i, l;
    if (!(fd = fopen("DANE.txt", "r")))
    {
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }

    int iloscLini = 0;
    while (iloscLini < MAX_LINES && fgets(d[iloscLini], MAX_LINE, fd) != (char*)NULL)
    {
        iloscLini++;
    }


    int n;
    printf("podaj n linie po ktorej chcesz wpisac tekst (liczac od 0): ");
    scanf("%d", &n);

    if (n >= iloscLini) {
        printf("Pozycja n, musi byc mniejsza od ilosci lini!");
        return -1;
    }

    char *text;
    printf("Podaj tekst do wstawienia: ");
    scanf("%s", text);


    fclose(fd);
    fd = NULL;
    printf("%d\n", iloscLini);
}
