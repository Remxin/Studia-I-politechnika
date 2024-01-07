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
    struct stud* p;
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
    STUDENT *prev = (STUDENT *)NULL;
    while (fgets(bufor, MAX_BUFOR, fd)) {
        B = (STUDENT*)malloc(sizeof(STUDENT));
        if (H == (STUDENT*)NULL) {
            H = B;
        } else {
            P->n = B;
        }

        if (!prev) {
            prev = B;
        } else {
            B->p = prev;
            prev = B;
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

void swap(STUDENT *a, STUDENT *b, STUDENT *c) {
    STUDENT *temp = a;
    *a = *b;
    *b = *temp;
    printf("1) %s, 2) %s, 3) %s\n", a->imie, b->imie, c->imie);
//    a->p = temp->p;
//    a->n = b;
//    b->n = c;
//    b->p = a;

}

// Funkcja do sortowania malejącego listy dwukierunkowej wg kwoty stypendium
void bubble_sort(STUDENT *head) {
    int swapped;
    STUDENT *ptr1;

    // Sprawdzamy, czy lista nie jest pusta
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->n != NULL) {
            // Porównujemy kwoty stypendiów i zamieniamy je, jeśli są w złej kolejności
            if (ptr1->stypendium < ptr1->n->stypendium) {
                printf("1) %s, 2) %s, 3) %s\n", ptr1->imie, ptr1->n->imie, (ptr1->n)->n->imie);

                swap(ptr1, ptr1->n, (ptr1->n)->n);
                swapped = 1;
            }
            ptr1 = ptr1->n;
        }
//        while (ptr1->p != NULL) ptr1 = ptr1->p;

    } while (swapped);
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
    bubble_sort(H);
    dispList1(); puts("---------------------------------------------------------------------\n");



    return 0;

}