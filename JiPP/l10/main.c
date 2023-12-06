#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996 6387)
#define MAX_BUFOR 1000

typedef struct stud {
    char* imie;
    char* nazwisko;
    int rok;
    char* adres;
    double stypendium;
    struct stud* n;
}STUDENT;

STUDENT* H;

FILE* fd = NULL;

void list1(FILE* plik)
{
    unsigned len;
    STUDENT* B = NULL, * P = NULL;
    char bufor[MAX_BUFOR];
    H = (STUDENT*)NULL;
    while (fgets(bufor, MAX_BUFOR, fd)) {
        B = (STUDENT*)malloc(sizeof(STUDENT));
        if (H == (STUDENT*)NULL)
        {
            H = B;
        }
        else
        {
            P->n = B;
        }
        B->n = (STUDENT*)NULL;

        len = (unsigned)strlen(bufor);
        printf("%d\n %s\n", len, bufor);
        bufor[len - 1] = '\0';
        B->imie = (char*)malloc(len);
        strcpy(B->imie, bufor);

        fgets(bufor, MAX_BUFOR, fd);
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        B->nazwisko = (char*)malloc(len);
        strcpy(B->nazwisko, bufor);

        fgets(bufor, MAX_BUFOR, fd);
        B->rok = atoi(bufor);

        fgets(bufor, MAX_BUFOR, fd);
        len = (unsigned)strlen(bufor);
        bufor[len - 1] = '\0';
        B->adres = (char*)malloc(len);
        strcpy(B->adres, bufor);

        fgets(bufor, MAX_BUFOR, fd);
        B->stypendium = atof(bufor);
        P = B;
    }
}

void dispList1()
{
    STUDENT* w;
    w = H;
    if (H == NULL)
    {
        printf("Lista pusta");
        return;
    }

    for (w = H; w != (STUDENT*)NULL; w = w->n)
    {
        printf("%p   %p\n", w, w->n);
        printf("%12s| %12s| %4d| %25s| %7.2lf\n", w->imie, w->nazwisko, w->rok, w->adres, w->stypendium);
    }
    /*
    while (w)
    {
        printf("%p   %p\n", w, w->n);
        printf("%12s| %12s| %4d| %25s| %7.2lf\n", w->imie, w->nazwisko, w->rok, w->adres, w->stypendium);
        w = w->n;
    }*/
}


int main()
{
    STUDENT* ms;

    fd = fopen("dane.txt", "r");
    if (fd == NULL) {
        printf("Nie mogę otworzyć pliku dane.txt do odczytu!\n");
        getchar();
        exit(1);
    }

    list1(fd);
//    dispList1(); puts("---------------------------------------------------------------------\n");
    //ms = max_s();
    //printf("%s %.2lf\n", ms->nazwisko, ms->stypendium);
    //addHeadList1();
    //addTailList1();
    //dispList1();puts("---------------------------------------------------------------------\n");
    //printf("dlugosc listy = %d\n", lenList1());
    //remHeadList1();
    //dispList1(); puts("---------------------------------------------------------------------\n");
    //remTailList1();
    //dispList1(); putchar('\n');
}