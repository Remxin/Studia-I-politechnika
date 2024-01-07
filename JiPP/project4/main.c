#include <stdio.h>
#include <malloc.h>

#define MAX_TABSIZE 256

// structures
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
} FIFO_T;

//enums
enum structures {
    LIFOL,
    LIFOT,
    FIFOL,
    FIFOT
};
enum actions {
    ADD,
    GET,
    SEARCH,
    LIST,
    LENGTH,
    DROP,
    END
};

enum fieldType {
    NAME,
    SURNAME,
    YEAROFBIRTH
};

// menu
extern void showMenu();
extern void showActionMenu();
extern void closeMenu();
extern void showFieldTypeMenu();

// error
extern void error(int nr, char *str);

// io
extern int getInt(char *text);
extern char *getString(char *text);

// LIFO list
extern void addLIFOLElement(LIFO *H);
extern void listLIFOL(LIFO* H);
extern int getLIFOLLen(LIFO *H);
extern LIFO *getLIFOLElement(LIFO *H);
extern LIFO *findLIFOElement(LIFO *H, enum fieldType ft, char *text, int yob);
extern void dropLIFOL(LIFO *H);

// LIFO tab
extern void addLIFOTElement(LIFO_T *H[MAX_TABSIZE], int *tabLen);
extern LIFO_T *getLIFOTElement(LIFO_T *H[MAX_TABSIZE], int *tabLen);
extern LIFO_T *getLIFOTElement(LIFO_T *H[MAX_TABSIZE], int *tabLen);
extern void listLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen);
extern void searchLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen, enum fieldType ft, char *text, int yob);
extern void dropLIFOT(LIFO_T *H[MAX_TABSIZE], int *tabLen);

// FIFO list
extern void addFIFOL(FIFO *H);
extern FIFO *getFIFOLElement(FIFO *H);
extern FIFO *findFIFOElement(FIFO *H, enum fieldType ft, char *text, int yob);
extern void listFIFOL(FIFO *H);
extern int lengthFIFOL(FIFO *H);
extern void dropFIFOL(FIFO *H);

// FIFO tab
extern void addFIFOT(FIFO_T *H[MAX_TABSIZE], int *tabLen);
extern FIFO_T *getFIFOTElement(FIFO_T *H[MAX_TABSIZE], int *tabLen);
extern FIFO_T *findFIFOTElement(FIFO_T *H[MAX_TABSIZE], int *tabLen, enum fieldType ft, char *text, int yob);
extern void listFIFOT(FIFO_T *H[MAX_TABSIZE], int tabLen);
extern void dropFIFOT(FIFO_T *H[MAX_TABSIZE], int *tabLen);



int main() {
    //
    LIFO *H;
    LIFO_T *LTab[MAX_TABSIZE];

    FIFO *HF;
    FIFO_T *FTab[MAX_TABSIZE];
    int tabLen = 0;
    // program
    enum structures structureChoice = 0;
    enum actions actionChoice = 0;
    showMenu();
    if (scanf("%d", &structureChoice) != 1) error(4, "Podano zly typ danych");
    if (structureChoice < 0 || structureChoice > 3) error(5, "Wybor moze byc tylko z przedzialu 1-4");

    printf("%d, %d", structureChoice, LIFOT);
    switch(structureChoice) {
        case LIFOL:
            H = (LIFO *)malloc(sizeof(LIFO));
            H->yearOfBirth = -1;
            break;
        case LIFOT:
            LTab[0] =  NULL;
            break;
        case FIFOL:
            HF = (FIFO *)malloc(sizeof(FIFO));
            HF->yearOfBirth = -1;
            break;
        case FIFOT:
            FTab[0] = NULL;
            break;

    }

    int doWhile = 1;
    while (doWhile) {
        printf("\n");
        showActionMenu();
        if (scanf("%d", &actionChoice) != 1) error(4, "Podano zly typ danych");
        if (actionChoice < 0 || actionChoice > 6) error(5, "Wybor moze byc tylko z przedzialu 1-4");

        switch(structureChoice) {
            case LIFOL:
                if (actionChoice == ADD) addLIFOLElement(H);
                else if (actionChoice == GET) {

                    getLIFOLElement(H);
                }
                else if (actionChoice == SEARCH) {
                    showFieldTypeMenu();
                    enum fieldType choice = getInt("Twoj wybor: ");
                    char *searchT = "";
                    int searchI = 0;

                    switch (choice) {
                        case NAME:
                            searchT= getString("Podaj szukane imie: ");
                            break;
                        case SURNAME:
                            searchT = getString("Podaj szukane nazwisko: ");
                            break;
                        case YEAROFBIRTH:
                            searchI = getInt("Podaj szukana date urodzenia");

                            break;
                    }
                    findLIFOElement(H, choice, searchT, searchI);

                }
                else if (actionChoice == LIST) listLIFOL(H);
                else if (actionChoice == LENGTH) {
                    int n = getLIFOLLen(H);
                    printf("Dlugosc listy LIFO: %d", n);
                }
                else if (actionChoice == DROP) {
                    dropLIFOL(H);
                    doWhile = 0;
                }
                else if (actionChoice == END) doWhile = 0;
                break;

            case LIFOT:
                if (actionChoice == ADD) {
                    addLIFOTElement(LTab, &tabLen);
                } else if (actionChoice == GET) {
                    getLIFOTElement(LTab, &tabLen);
                } else if (actionChoice == SEARCH) {
                    showFieldTypeMenu();
                    enum fieldType choice = getInt("Twoj wybor: ");
                    char *searchT = "";
                    int searchI = 0;

                    switch (choice) {
                        case NAME:
                            searchT= getString("Podaj szukane imie: ");
                            break;
                        case SURNAME:
                            searchT = getString("Podaj szukane nazwisko: ");
                            break;
                        case YEAROFBIRTH:
                            searchI = getInt("Podaj szukana date urodzenia");

                            break;
                    }
                    searchLIFOT(LTab, &tabLen, choice, searchT, searchI);
                } else if (actionChoice == LIST) {
                    listLIFOT(LTab, &tabLen);
                } else if (actionChoice == LENGTH) {
                    printf("Dlugosc tablicy LIFO: %d", tabLen);
                } else if (actionChoice == DROP) {
                    dropLIFOT(LTab, &tabLen);
                    doWhile = 0;
                } else if (actionChoice == END) doWhile = 0;
                break;

            case FIFOL:
                if (actionChoice == ADD) {
                    addFIFOL(HF);
                } else if (actionChoice == GET) {
                    getFIFOLElement(HF);
                } else if (actionChoice == SEARCH) {
                    showFieldTypeMenu();
                    enum fieldType choice = getInt("Twoj wybor: ");
                    char *searchT = "";
                    int searchI = 0;

                    switch (choice) {
                        case NAME:
                            searchT= getString("Podaj szukane imie: ");
                            break;
                        case SURNAME:
                            searchT = getString("Podaj szukane nazwisko: ");
                            break;
                        case YEAROFBIRTH:
                            searchI = getInt("Podaj szukana date urodzenia");

                            break;
                    }
                    findFIFOElement(HF, choice, searchT, searchI);
                } else if (actionChoice == LIST) {
                    listFIFOL(HF);
                } else if (actionChoice == LENGTH) {
                    int n = lengthFIFOL(HF);
                    printf("Dlugosc listy FIFO: %d", n);
                } else if (actionChoice == DROP) {
                    dropFIFOL(HF);
                    doWhile = 0;
                } else if (actionChoice == END) doWhile = 0;
                break;
            case FIFOT:
                if (actionChoice == ADD) addFIFOT(FTab, &tabLen);
                else if (actionChoice == GET) getFIFOTElement(FTab, &tabLen);
                else if (actionChoice == SEARCH) {
                    showFieldTypeMenu();
                    enum fieldType choice = getInt("Twoj wybor: ");
                    char *searchT = "";
                    int searchI = 0;

                    switch (choice) {
                        case NAME:
                            searchT= getString("Podaj szukane imie: ");
                            break;
                        case SURNAME:
                            searchT = getString("Podaj szukane nazwisko: ");
                            break;
                        case YEAROFBIRTH:
                            searchI = getInt("Podaj szukana date urodzenia");

                            break;
                    }
                    findFIFOTElement(FTab, &tabLen, choice, searchT, searchI);
                } else if (actionChoice == LIST) {
                    listFIFOT(FTab, tabLen);
                } else if (actionChoice == LENGTH) {
                    printf("Dlugosc tablicy FIFO: %d", tabLen);
                } else if (actionChoice == DROP) {
                    dropFIFOT(FTab, &tabLen);
                    doWhile = 0;
                } else if (actionChoice == END) doWhile = 0;

                break;
        }

    }
    closeMenu();
    return 0;
}