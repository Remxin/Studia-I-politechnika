
#include <stdlib.h>

double **falloc2DMatrix(int n) {
    double **tab = (double **)malloc(sizeof(double *) * n);
    for (int i = 0; i < n; i++) {
        tab[i] = (double *)malloc(sizeof(double) * n);
    }

    return tab;
}

double *falloc1DMatrix(int n) {
    double *tab = (double *)malloc(sizeof(double) *n);
    return tab;
}

void ffree1DMatrix(double *tab) {
    free(tab);
    tab = (double *)NULL;
}

void ffree2DMatrix(double **tab, int n) {
    for (int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);
    tab = (double **) NULL;
}