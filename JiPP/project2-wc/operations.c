
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define BUFFOR_LEN 200
#define MAX_SLOW 16
extern void Pisz(char c);
extern void error(int nr, char *str);


char **SlowaILitery(char *text) {
    char buffor[MAX_SLOW][BUFFOR_LEN];
    char znak;
    int i = 0;

    int bufforLen = 0;

    char wordBuffer[BUFFOR_LEN];
    int wordBufforLen = 0;
    int maxWordLen = 0;

    while ((znak = text[i]) != '\0') {

        if (znak == ' ' || znak == '\n') {
            wordBuffer[wordBufforLen] = '\0';
            (int)strlen(wordBuffer) > maxWordLen ? maxWordLen = (int)strlen(wordBuffer) : NULL;
            strcpy(buffor[bufforLen++], wordBuffer);
            memset(wordBuffer, 0, wordBufforLen);
            wordBufforLen = 0;

        } else {
            wordBuffer[wordBufforLen++] = znak;
        }
        i++;
    }

    char **tab = malloc(sizeof(char*) * bufforLen);

    for (i = 0; i < bufforLen; i++) {
        tab[i] = calloc(maxWordLen,sizeof(char));
        strcpy(tab[i], buffor[i]);
        tab[i][maxWordLen] = '\0';
    }



    return tab;
}

int getMaxVal (char **tab) {
    int max = 0;
    int i = 0;
    while (tab[i] != (char*)0) {
        if (strlen(tab[i]) > max) max = (int)strlen(tab[i]);
        i++;
    }

    return max;
}

int getTabLen(char **tab) {
    int i = 0;
    while (tab[i] != (char*)0) {
        i++;
    }
    return i;
}

void printNewTextTab(int rows, int cols, char **textTab, int choice) {
    int wordSize;

    for (int i = 0; i < rows; i++) { // for test
        for (int j = 0; j < cols; j++) {
            wordSize = (int)strlen(textTab[j]);

            if (choice == 1) {
                if (textTab[j][i] != (char)0) {
                    printf("%c\t", textTab[j][i]);
                    Pisz(textTab[j][i]);
                }
                else {
                    printf(" \t");
                    Pisz(' ');
                }
            } else {
                if (i < rows - wordSize) {
                    printf(" \t");
                    Pisz(' ');
                }
                else {
                    if (textTab[j][i - (rows-wordSize)] != (char)0){
                        printf("%c\t", textTab[j][i - (rows-wordSize)]);
                        Pisz(textTab[j][i - (rows-wordSize)]);
                    }
                    else {
                        printf(" \t");
                        Pisz(' ');
                    }
                }
            }

        }
        printf("\n");
        Pisz('\n');
    }

}