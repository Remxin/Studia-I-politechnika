#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFOR_LEN 1000
#define MAX_STRLEN 1000


extern char *InputText(char *text);
extern char **SlowaILitery(char *text);
extern int getMaxVal (char **tab);
extern int getTabLen(char **tab);
extern void printNewTextTab(int rows, int cols, char **textTab, int choice);
extern void error(int nr, char *str);
extern void InitPlik();
void ZamknijPlik();

int main() {
    setlocale(LC_ALL, "852");
    printf("%s", "ęąćźżół");
//    InitPlik();
//
//    char *originalText = InputText("Podaj ciag znakow: ");
//    char **words = SlowaILitery(originalText);
//////
//////
//    int rows = getMaxVal(words);
//    int cols = getTabLen(words);
//////
//    int choice = 1;
//    printf("Wybierz gdzie ma byc wyrownany tekst:\n1) gora\n2) dol\n: ");
//    if (scanf("%d", &choice) != 1) error(5, "zly typ danych dla wyboru!");
//    if (choice != 1 && choice != 2) error(6, "wyboru mozna dokonac tylko pomiedzy 1, a 2");
//
//    printNewTextTab(rows, cols, words, choice);
//
    ZamknijPlik();
    return 0;
}