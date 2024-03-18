
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TABSIZE 256

// structures
typedef struct fifo {
    char *name;
    char *surname;
    int yearOfBirth;
    struct fifo *next;
} FIFO;

typedef struct fifot {
    char *name;
    char *surname;
    int yearOfBirth;
} FIFOT;

// enums for actions
enum actions {
    ADD,
    GET,
    SEARCH,
    LENGTH,
    DROP
};

enum fieldType {
    NAME,
    SURNAME,
    YEAROFBIRTH
};
// error
extern void error(int nr, char *str);

// io
extern char *getString(char *text);
extern int getInt(char *text);

// fifo list
void addFIFOL(FIFO *H) {
    FIFO *new = (FIFO *)malloc(sizeof(FIFO));
    char *name = getString("Podaj imie: ");
    char *surname = getString("Podaj nazwisko: ");
    int yob = getInt("Podaj rok urodzenia: ");
    if (yob < 0) error(5, "Rok urodzenia musi byc wiekszy od 0");

    if (!H || H->yearOfBirth < 0) { // no elements
        H->name = (char *)malloc(sizeof(name));
        H->surname = (char *)malloc(sizeof(surname));

        strcpy(H->name, name);
        strcpy(H->surname, surname);
        H->yearOfBirth = yob;
        H->next = NULL;
    } else { // element exists
        new->name = (char *)malloc(sizeof(name));
        new->surname = (char *)malloc(sizeof(surname));

        strcpy(new->name, name);
        strcpy(new->surname, surname);
        new->yearOfBirth = yob;
        new->next = NULL;
        H->next = new;
    }
}

FIFO *getFIFOLElement(FIFO *H) {
    if (H->yearOfBirth < 0) {
        printf("No elements on the list!");
        return (FIFO *)NULL;
    } else {
        FIFO *temp = H;
        printf("found element details:\n"
               "%s\t\t%s\t\t%d\t\t\n", temp->name, temp->surname, temp->yearOfBirth);
        if (H->next) *H = *H->next;
        else H->yearOfBirth = -1;

        return temp;
    }

}

void listFIFOL(FIFO *H) {
    FIFO *temp = H;
    int i = 0;
    printf("\nZawartosc tablicy FIFO\nnumer\t\timie\t\tnazwisko\t\trok urodzenia\t\t\n----------------------------\n");

    while (temp != NULL) {
        printf("%d)\t\t%s\t\t%s\t\t%d\n\n", i, temp->name, temp->surname, temp->yearOfBirth);
        temp = temp->next;
        i++;
    }
}

FIFO *findFIFOElement(FIFO *H, enum fieldType ft, char *text, int yob) {
    FIFO *temp = H;

    switch (ft) {
        case NAME:
            while (temp != (FIFO *)NULL && strcmp(temp->name, text) != 0) {
                temp = temp->next;
            }
            break;
        case SURNAME:
            while (temp != (FIFO *)NULL && strcmp(temp->surname, text) != 0) {
                temp = temp->next;
            }
            break;
        case YEAROFBIRTH:
            while (temp != (FIFO *)NULL && temp->yearOfBirth != yob) {
                temp = temp->next;
            }
            break;
    }
    if (temp == (FIFO *) NULL) {
        printf("Element not found\n\n");
    } else {
        printf("found element details:\n"
               "%s\t\t%s\t\t%d\t\t\n", temp->name, temp->surname, temp->yearOfBirth);
    }

    return temp;
}

int lengthFIFOL(FIFO *H) {
    FIFO *temp = H;
    int i = 0;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

void dropFIFOL(FIFO *H) {
    FIFO *temp = H;
    while (H != NULL) {
        free(H->name);
        free(H->surname);
        temp = H;
        H = H->next;
        free(temp);
    }
}

// FIFO tab
void addFIFOT(FIFOT *H[MAX_TABSIZE], int *tabLen) {
    FIFOT *new = (FIFOT *)malloc(sizeof(FIFOT));
    char *name = getString("Podaj imie: ");
    char *surname = getString("Podaj nazwisko: ");
    int yob = getInt("Podaj rok urodzenia: ");
    if (yob < 0) error(5, "Rok urodzenia musi byc wiekszy od 0");

    new->name = (char *)malloc(sizeof(name));
    new->surname = (char *)malloc(sizeof(surname));

    strcpy(new->name, name);
    strcpy(new->surname, surname);
    new->yearOfBirth = yob;
    H[*tabLen] = new;
    (*tabLen)++;
}

FIFOT *getFIFOTElement(FIFOT *H[MAX_TABSIZE], int *tabLen) {
    if (*tabLen == 0) {
        printf("No elements on the list!");
        return (FIFOT *)NULL;
    }

    FIFOT *ret = H[0];

    printf("---- otrzymany element -----\n");
    printf("\t\t%s\t\t%s\t\t%d\n\n", ret->name, ret->surname, ret->yearOfBirth);

    for (int i = 0; i < *tabLen - 1; i ++) {
        *H[i] = *H[i+1];
    }

    (*tabLen)--;



    return ret;
}

FIFOT *findFIFOTElement(FIFOT *H[MAX_TABSIZE], int *tabLen, enum fieldType ft, char *text, int yob) {
    FIFOT *temp = NULL;

    switch (ft) {
        case NAME:
            for (int i = 0; i < *tabLen; i++) {
                if (strcmp(H[i]->name, text) == 0) temp = H[i];
            }
            break;
        case SURNAME:
            for (int i = 0; i < *tabLen; i++) {
                if (strcmp(H[i]->surname, text) == 0) temp = H[i];
            }
            break;
        case YEAROFBIRTH:
            for (int i = 0; i < *tabLen; i++) {
                if (H[i]->yearOfBirth == yob) temp = H[i];
            }
            break;
    }
    if (temp == (FIFOT *) NULL) {
        printf("Element not found\n\n");
    } else {
        printf("found element details:\n"
               "%s\t\t%s\t\t%d\t\t\n", temp->name, temp->surname, temp->yearOfBirth);
    }

    return temp;
}

void listFIFOT(FIFOT *H[MAX_TABSIZE], int tabLen) {
    printf("\nZawartosc tablicy FIFO\nnumer\t\timie\t\tnazwisko\t\trok urodzenia\t\t\n----------------------------\n");
    for (int i = 0; i < tabLen; i++) {
        printf("%d)\t\t%s\t\t%s\t\t%d\n\n", i, H[i]->name, H[i]->surname, H[i]->yearOfBirth);
    }
}

void dropFIFOT(FIFOT *H[MAX_TABSIZE], int *tabLen) {
    for (int i = 0; i < *tabLen; i++) {
        free(H[i]->name);
        free(H[i]->surname);
        free(H[i]);
    }
    *tabLen = 0;
}