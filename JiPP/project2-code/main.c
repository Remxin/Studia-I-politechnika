
#include <printf.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "header.h"

#define BUFFOR_LEN 5500
#define MAX_STRLEN 5500


int main() { // wyczyścić standardowe wejście + polskie znaki
    setlocale(LC_ALL, "pl_PL.UTF-8");
    InitPlik();


    char *originalText = InputText("Podaj ciag znakow: ");
    int *encodedText = encodeText(originalText); 
    int i = 0;

    int rows, cols;
    int **words = SlowaILitery(encodedText, &rows, &cols);

    clearInputBuffer(); // !only for pasting content


    int choice;
    printf("Wybierz gdzie ma byc wyrownany tekst:\n1) gora\n2) dol\n: ");
    if (scanf("%d", &choice) != 1) error(5, "zly typ danych dla wyboru!");
    if (choice != 1 && choice != 2) error(6, "wyboru mozna dokonac tylko pomiedzy 1, a 2");

    printNewTextTab(rows, cols, words, choice);

    ZamknijPlik();
    return 0;
}