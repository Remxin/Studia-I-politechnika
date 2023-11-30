
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define BUFFOR_LEN 1200
#define MAX_SLOW 1450

int **SlowaILitery(int *text, int *rows, int *cols) {
    int buffor[MAX_SLOW][BUFFOR_LEN];
    int num;
    int i = 0, j = 0;

    int bufforLen = 0;

    int numBuffer[BUFFOR_LEN];
    int numBufferLen = 0;
    int maxWordLen = 0;

    while ((num = text[i])) {
        if (num == 32 || num == -1) {
            buffor[bufforLen][numBufferLen] = -1;
            bufforLen++;
            if (numBufferLen > maxWordLen) maxWordLen = numBufferLen;
            numBufferLen = 0;
            if (num == -1) break;
        } else {
            buffor[bufforLen][numBufferLen++] = num;
        }
        i++;
    }

    int **tab = (int **) malloc(sizeof(int*) * bufforLen);

    for (i = 0; i < bufforLen; i++) {
            tab[i] = (int *) malloc(sizeof(int) * maxWordLen);
        for (j = 0; j < maxWordLen; j++) {
            if (!buffor[i][j] || buffor[i][j] == -1) tab[i][j] = -1;
            else tab[i][j] = buffor[i][j];
          
        }
    }

    *rows = maxWordLen;
    *cols = bufforLen;

    return tab;
}


void printPolish(int numVal) {
    if (numVal == -1 || !numVal || numVal == 0)  {

    } else if (numVal < 128) {
        printf("%c", (char) numVal);
        Pisz((char) numVal);
    } else {
        switch (numVal) {  
            case 128:
                printf("%s", "ą");
                Piszstr("ą");
            break;
            case 129:
                printf("%s", "ń");
                Piszstr("ń");
                break;
            case 130:
                printf("%s", "ę");
                Piszstr("ę");
                break;
            case 131:
                printf("%s", "ć");
                Piszstr("ę");
                break;
            case 132:
                printf("%s", "ó");
                Piszstr("ó");
                break;
            case 133:
                printf("%s", "ś");
                Piszstr("ś");
                break;
            case 134:
                printf("%s", "ź");
                Piszstr("ź");
                break;
            case 135:
                printf("%s", "ż");
                Piszstr("ż");
                break;
            case 136:
                printf("%s", "ł");
                Piszstr("ł");
                break;
         
            }
    }
    printf("\t");
    Pisz('\t');
}

int getIntRowLen(int *row, int elements) {
    int sum = 0;
    for (int i = 0; i < elements; i++) {
        if (row[i] != -1) sum++;
    }

    return sum;
}   

void printNewTextTab(int rows, int cols, int **textTab, int choice) {
    int wordSize;


    for (int i = 0; i < rows; i++) { // for test
        for (int j = 0; j < cols; j++) {
            wordSize = getIntRowLen(textTab[j], rows);
            

            if (choice == 1) {
                if (textTab[j][i] != -1) {
                    printPolish(textTab[j][i]);
                }
                else {
                    printPolish(32);
                }
            } else {
                if (i < rows - wordSize) {
                    printPolish(32);
                }
                else {
                    if (textTab[j][i - (rows-wordSize)] != -1){
                        if (!textTab[j][i - (rows-wordSize)]) printf(" \t");
                        else printPolish(textTab[j][i - (rows-wordSize)]);
                    }
                    else {
                        printPolish(32);
                    }
                }
            }

        }
        printf("\n");
        Pisz('\n');
    }

}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getPolishCharInt(int c1, int c2) {
    int chrnum = c1 + c2;
  
    switch (chrnum) {
        case -183:
            if (c1 == -60) chrnum = 128; // for ą 
            else chrnum = 129; // for ń
            break;
        case -163:
            chrnum = 130; //ę 
            break;
        case -126:
        case -181:
            chrnum = 131; // ć
            break;
        case -138:
            chrnum = 132; // ó
            break;
        case -160:
            chrnum = 133; //ś
            break;
        case -129:
            chrnum = 134; // ź
            break;
        case -127:
            chrnum = 135; // ż
            break;
        case -185:
            chrnum = 136; // ł
            break;
    }
      return chrnum;

        
}

int *encodeText(char *text) {
    int i = 0;
    char c;
    int hashedTab[260];
    int hashedLen = 0;
 
    while ((c = text[i]) != '\0') {
        if (c < 0) {
            int num = getPolishCharInt(c, text[i+1]);
            hashedTab[hashedLen] = num;

            i++;
        } else {
            hashedTab[hashedLen] = (int) c;
        }
            
        hashedLen++;
        i++;
    }
    hashedTab[hashedLen -1] = -1;


    return hashedTab;
}


