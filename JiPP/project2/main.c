
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFOR_LEN 5500
#define MAX_STRLEN 5500


extern char *InputText(char *text);
extern char **SlowaILitery(char *text);
extern int getMaxVal (char **tab);
extern int getTabLen(char **tab);
extern void printNewTextTab(int rows, int cols, char **textTab, int choice);
extern void error(int nr, char *str);
extern void InitPlik();
<<<<<<< HEAD
extern void Pisz(char c);
void ZamknijPlik();

int main() {
    setlocale( LC_ALL, "" );
=======
extern void clearInputBuffer();
extern void ZamknijPlik();

int main() { // wyczyścić standardowe wejście + polskie znaki
    setlocale(LC_ALL, "pl_PL.UTF-8");
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716
    InitPlik();

    char *originalText = "alą mę kotółźż";
    for (int i = 0; i < strlen(originalText); i++) {
        printf("%c", originalText[i]);
    }
    printf("%s", originalText);
    char **words = SlowaILitery(originalText);
<<<<<<< HEAD
//    for (int i = 0; i < sizeof(words)  +1; i++) {
//        printf("%s\n", words[i]);
//    }
////
////
//    int rows = getMaxVal(words);
//    int cols = getTabLen(words);
//////
//    int choice = 1;
//    printf("Wybierz gdzie ma byc wyrownany tekst:\n1) gora\n2) dol\n: ");
//    if (scanf("%d", &choice) != 1) error(5, "zly typ danych dla wyboru!");
//    if (choice != 1 && choice != 2) error(6, "wyboru mozna dokonac tylko pomiedzy 1, a 2");
=======
    clearInputBuffer();

    int rows = getMaxVal(words);
    int cols = getTabLen(words);

    int choice;
    printf("Wybierz gdzie ma byc wyrownany tekst:\n1) gora\n2) dol\n: ");
    if (scanf("%d", &choice) != 1) error(5, "zly typ danych dla wyboru!");
    if (choice != 1 && choice != 2) error(6, "wyboru mozna dokonac tylko pomiedzy 1, a 2");
>>>>>>> 049049d255b77a116506ba7e6eaba467df74c716

//    printNewTextTab(rows, cols, words, choice);

    ZamknijPlik();
    return 0;
}