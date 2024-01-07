#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996 6387)
#define MAX_BUFOR 80

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
        printf("%12s| %12s| %4d| %25s| %7.2lf\n", w->imie, w->nazwisko, w->rok, w->adres, w->stypendium);
    }

}

STUDENT *max_s() {
    STUDENT *m;
    STUDENT *temp;
    temp = H;
    double max;

    while (temp->n != (STUDENT *)NULL) {
        if (temp->stypendium > max) {
            max = temp->stypendium;
            m = temp;
        }
        temp = temp->n;
    }

    return m;
}

void addHeadList1() {
    char imie[MAX_BUFOR];
    char nazwisko[MAX_BUFOR];
    int rok;
    char adres[MAX_BUFOR];
    double stypendium;

    // getting data from user
    printf("Podaj imie: ");
    if ((scanf("%s", imie) != 1)) perror("blad we wczytywaniu imienia");
    printf("Podaj nazwisko: ");
    if ((scanf("%s", nazwisko) != 1)) perror("blad we wczytywaniu nazwiska");
    printf("Podaj rok: ");
    if ((scanf("%d", &rok) != 1)) perror("blad we wczytywaniu roku");
    printf("Podaj adres: ");
    fflush(stdin);
    fgets(adres, MAX_BUFOR, stdin);

    printf("Podaj stypendium: ");
    if ((scanf("%lf", &stypendium) != 1)) perror("blad we wczytywaniu stypendium");

    //
    unsigned len = 0;
    STUDENT *new = NULL;
    new = (STUDENT *)malloc(sizeof(STUDENT));
    new->n = H;
    len = (unsigned) strlen(imie);
    imie[len] = '\0';

    new->imie = (char*)malloc(sizeof(char) * len);
    strcpy(new->imie, imie);

    len = (unsigned )strlen(nazwisko);
    nazwisko[len] = '\0';
    new->nazwisko = (char*)malloc(sizeof(char) * len);
    strcpy(new->nazwisko, nazwisko);

    new->rok = rok;

    len = (unsigned)strlen(adres);
    adres[len] = '\0';
    new->adres = (char *)malloc(sizeof(char) * len);
    strcpy(new->adres, adres);
    new->stypendium = stypendium;

    H = new;
}

void addTailList1() {
    char imie[MAX_BUFOR];
    char nazwisko[MAX_BUFOR];
    int rok;
    char adres[MAX_BUFOR];
    double stypendium;

    // getting data from user
    printf("Podaj imie: ");
    if ((scanf("%s", imie) != 1)) perror("blad we wczytywaniu imienia");
    printf("Podaj nazwisko: ");
    if ((scanf("%s", nazwisko) != 1)) perror("blad we wczytywaniu nazwiska");
    printf("Podaj rok: ");
    if ((scanf("%d", &rok) != 1)) perror("blad we wczytywaniu roku");
    printf("Podaj adres: ");
    fflush(stdin);
    fgets(adres, MAX_BUFOR, stdin);

    printf("Podaj stypendium: ");
    if ((scanf("%lf", &stypendium) != 1)) perror("blad we wczytywaniu stypendium");

    //
    unsigned len = 0;
    STUDENT *new = NULL;
    new = (STUDENT *)malloc(sizeof(STUDENT));
    new->n = (STUDENT*) NULL;
    len = (unsigned) strlen(imie);
    imie[len] = '\0';

    new->imie = (char*)malloc(sizeof(char) * len);
    strcpy(new->imie, imie);

    len = (unsigned )strlen(nazwisko);
    nazwisko[len] = '\0';
    new->nazwisko = (char*)malloc(sizeof(char) * len);
    strcpy(new->nazwisko, nazwisko);

    new->rok = rok;

    len = (unsigned)strlen(adres);
    adres[len] = '\0';
    new->adres = (char *)malloc(sizeof(char) * len);
    strcpy(new->adres, adres);
    new->stypendium = stypendium;

    STUDENT *temp = H;
    while (temp->n != (STUDENT*)NULL) {
        temp = temp->n;
    };
    temp->n = new;

}

int lenList1() {
    int len = 1;
    STUDENT *temp = H;
    while (temp->n != (STUDENT*) NULL) {
        len++;
        temp = temp->n;
    }

    return len;
}

void remHeadList1() {
    STUDENT *temp = H;
    H = H->n;
    free(temp->imie);
    free(temp->nazwisko);
    free(temp->adres);
    free(temp);
}

void remTailList1() {
    STUDENT *temp = H;
    while ((temp->n)->n != (STUDENT *)NULL) {
        temp = temp->n;
    }
    free((temp->n)->imie);
    free((temp->n)->nazwisko);
    free((temp->n)->adres);
    free(temp->n);
    temp->n = (STUDENT *)NULL;

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

    dispList1(); puts("---------------------------------------------------------------------\n");



    ms = max_s();
    printf("max: %lf\n", ms->stypendium);
    //printf("%s %.2lf\n", ms->nazwisko, ms->stypendium);
//    addHeadList1();
//    addTailList1();
//    remHeadList1();
    printf("dlugosc listy = %d\n", lenList1());
    //dispList1(); puts("---------------------------------------------------------------------\n");
    remTailList1();
    dispList1();puts("---------------------------------------------------------------------\n");
    //dispList1(); putchar('\n');
}