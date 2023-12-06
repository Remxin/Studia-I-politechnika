#include <stdio.h>
#include <stdlib.h>

#define INT_BUFFOR_SIZE 100

FILE *fdin;
FILE *fdout;

extern void error(int nr, char *str);
extern double *falloc1DMatrix(int n);
extern double **falloc2DMatrix(int n);
extern double *getTabRow(char *text, int n);

void InitFiles() {
    if (!(fdin = fopen("dane.txt", "r"))) error(2, "blad w otwarciu pliku z danymi");
    if (!(fdout = fopen("wyniki.txt", "w"))) error(2, "blad w otwarciu pliku z wynikami");
}

void CloseFiles() {
    fclose(fdin);
    fclose(fdout);
    fdin = NULL;
    fdout = NULL;
}

int getMatrixDim() {
    char buffor[INT_BUFFOR_SIZE];
    if (!(fgets(buffor, INT_BUFFOR_SIZE, fdin ))) error(7, "blad odczytu danych z pliku");
    int dim = atoi(buffor);

    return dim;
}

double **get2Dmatrix(int n) {
    double **returnTab = falloc2DMatrix(n);

    int iter = 0;
    char buffor[INT_BUFFOR_SIZE];
    while (iter < n) {
        if (!(fgets(buffor, INT_BUFFOR_SIZE, fdin))) error(7, "blad odczytu danych (pobieranie matrycy 2D");
        returnTab[iter] = getTabRow(buffor, n);
        iter++;
    }

    return returnTab;
}

double *get1Dmatrix(int n) {
    double *matrix = falloc1DMatrix(n);
    int iter = 0;
    char buffor[INT_BUFFOR_SIZE];
    char *ptr;
    while (iter < n) {
        if (!(fgets(buffor, INT_BUFFOR_SIZE, fdin))) error(7, "blad odczytu danych (pobieranie matrycy 1D)");
        matrix[iter] = strtod(buffor, &ptr);
        iter++;
    }

    return matrix;
}

void writeResults(double *x,int dim, int iter) {
    fprintf(fdout, "Otrzymano wymagana precyzje w liczbie iteracji: %d\n", iter);
    printf("Otrzymano wymagana precyzje w liczbie iteracji: %d\n", iter);
    for (int i = 0; i < dim; i++) {
        fprintf(fdout, "x%d: %lf\n", i, x[i]);
        printf("x%d: %lf\n", i, x[i]);
    }
}