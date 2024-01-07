#include <malloc.h>
#include <string.h>
#include <stdio.h>

#define MAX_TABSIZE 256

// enums
typedef struct lifo {
    char *name;
    char *surname;
    int yearOfBirth;
    struct lifo *next;
} LIFO;

typedef struct lifot {
    char *name;
    char *surname;
    int yearOfBirth;
} LIFO_T;

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

// for list

void listLIFOL(LIFO* H) {
    int i = 1;
    LIFO *temp = H;
    printf("%s, %s\n\n", H->name, H->surname);
    printf("\nZawartosc listy LIFO\nnumer\t\timie\t\tnazwisko\t\trok urodzenia\t\t\n----------------------------\n");



    while (temp != (LIFO *)NULL && temp->yearOfBirth != -1) {
        printf("%d)\t\t%s\t\t%s\t\t%d\n\n", i, temp->name, temp->surname, temp->yearOfBirth);
        temp = temp->next;
        i++;
    }
}

void addLIFOLElement(LIFO *H) {
    // getting data from user
    char *name = getString("Podaj imie: ");
    char *surname = getString("Podaj nazwisko: ");
    int yob = getInt("Podaj rok urodzenia: ");
    if (yob < 0) error(5, "Rok urodzenia musi byc wiekszy od 0");

    if (H->yearOfBirth < 0) { // empty list
        // assigning values
        H->name = (char *)malloc(sizeof(name));
        strcpy(H->name, name);
        H->surname = (char *)malloc(sizeof(surname));
        strcpy(H->surname, surname);
        H->yearOfBirth = yob;
        H->next = (LIFO *)NULL;

       } else { // list not empty
        LIFO *cpy = malloc(sizeof(LIFO));
        *cpy = *H;
        LIFO *temp = (LIFO *)malloc(sizeof(LIFO));
        temp->name = (char *)malloc(sizeof(name));
        temp->surname = (char *)malloc(sizeof(surname));

        strcpy(temp->name, name);
        strcpy(temp->surname, surname);
        temp->yearOfBirth = yob;
        temp->next = (LIFO *)NULL;
        *H = *temp;
        H->next = cpy;
    }
}

int getLIFOLLen(LIFO *H) {
    LIFO *temp = H;
    int i = 0;
    while (temp != (LIFO *)NULL && temp->yearOfBirth != -1) {
        temp = temp->next;
        i++;
    }
    return i;
}
//
LIFO *getLIFOLElement(LIFO *H) {
    if (H->yearOfBirth < 0) {
        printf("No elements on the list!");
        return NULL;
    }

    LIFO *temp = H;


    printf("found element details:\n"
           "%s\t\t%s\t\t%d\t\t\n", temp->name, temp->surname, temp->yearOfBirth);
    if (H->next != (LIFO *)NULL) {
        *H = *H->next;
    } else {
        H->yearOfBirth = -1;
    }
    return temp;
}

LIFO *findLIFOElement(LIFO *H, enum fieldType ft, char *text, int yob) {
    LIFO *temp = H;

    switch (ft) {
        case NAME:
            while (temp != (LIFO *)NULL && strcmp(temp->name, text) != 0) {
                temp = temp->next;
            }
            break;
        case SURNAME:
            while (temp != (LIFO *)NULL && strcmp(temp->surname, text) != 0) {
                temp = temp->next;
            }
            break;
        case YEAROFBIRTH:
            while (temp != (LIFO *)NULL && temp->yearOfBirth != yob) {
                temp = temp->next;
            }
            break;
    }
    if (temp == (LIFO *) NULL) {
        printf("Element not found\n\n");
    } else {
        printf("found element details:\n"
               "%s\t\t%s\t\t%d\t\t\n", temp->name, temp->surname, temp->yearOfBirth);
    }

    return temp;
}

void dropLIFOL(LIFO *H) {
    LIFO *temp;
    while(H->next) {
        free(H->name);
        free(H->surname);
        temp = H;
        H = H->next;
        free(temp);
    }

}




// for LIFO table

void addLIFOTElement(LIFO_T *H[MAX_TABSIZE], int *tabLen) {
    LIFO_T *new = (LIFO_T*)malloc(sizeof(LIFO_T));
    char *name = getString("Podaj imie: ");
    char *surname = getString("Podaj nazwisko: ");
    int yob = getInt("Podaj rok urodzenia: ");
    if (yob < 0) error(5, "Rok urodzenia musi byc wiekszy od 0");


    // assigning values
    new->name = (char *)malloc(sizeof(name));
    strcpy(new->name, name);
    new->surname = (char *)malloc(sizeof(surname));
    strcpy(new->surname, surname);
    new->yearOfBirth = yob;

    H[*tabLen] = new;
    (*tabLen)++;
}

LIFO_T *getLIFOTElement(LIFO_T *H[MAX_TABSIZE], int *tabLen) {
    if (*tabLen == 0) {
        printf("No elements in the tab!");
        return NULL;
    }

    LIFO_T *ret = H[*tabLen - 1];
    H[*tabLen - 1] = NULL;

    (*tabLen)--;
    printf("---- otrzymany element -----\n");
    printf("\t\t%s\t\t%s\t\t%d\n\n", ret->name, ret->surname, ret->yearOfBirth);
    return ret;
}

void listLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen) {
    printf("\nZawartosc tablicy LIFO\nnumer\t\timie\t\tnazwisko\t\trok urodzenia\t\t\n----------------------------\n");
    for(int i = 0; i < *tabLen; i++) {
        printf("%d)\t\t%s\t\t%s\t\t%d\n\n", i, H[i]->name, H[i]->surname, H[i]->yearOfBirth);
    }

}

void searchLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen, enum fieldType ft, char *text, int yob) {
    int retIndex = -1;
    switch (ft) {
        case NAME:
            for (int i = 0; i < *tabLen; i++) {
                if (strcmp(H[i]->name, text) == 0) {
                    retIndex = i;
                    break;
                }
            }

            break;
        case SURNAME:
            for (int i = 0; i < *tabLen; i++) {
                if (strcmp(H[i]->surname, text) == 0) {
                    retIndex = i;
                    break;
                }
            }

            break;
        case YEAROFBIRTH:
            for (int i = 0; i < *tabLen; i++) {
                if (H[i]->yearOfBirth == yob) {
                    retIndex = i;
                    break;
                }
            }
            break;

    }
    if (retIndex < 0) {
        printf("Element not found!");
    } else {
        printf("%d)\t\t%s\t\t%s\t\t%d\n\n", retIndex, H[retIndex]->name, H[retIndex]->surname, H[retIndex]->yearOfBirth);
    }
}

void dropLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen) {
    for (int i = 0; i < *tabLen; i++) {
        free(H[i]->name);
        free(H[i]->surname);
        free(H[i]);
        H[i] = NULL;
    }
    *tabLen = 0;
}
