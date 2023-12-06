#include <stdlib.h>
#include <printf.h>
#include <string.h>

#define INT_BUFFOR_SIZE 10
#define S_SIZE 256

extern double *falloc1DMatrix(int n);

void divideA(double **A, double **L, double **D, double **U, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i < j) {
                U[i][j] = A[i][j];
                L[i][j] = 0.;
                D[i][j] = 0.;
            } else if (i > j) {
                L[i][j] = A[i][j];
                U[i][j] = 0.;
                D[i][j] = 0.;
            } else {
                D[i][j] = A[i][j];
                U[i][j] = 0.;
                L[i][j] = 0.;
            }
        }
    }
}

double *getTabRow(char *text, int n) {
    double *row = falloc1DMatrix(n);

    char *delim = "\t ";
    char *p;
    char *ptr = strtok(text, delim);

    int i = 0;
    while(ptr != NULL)
    {
        row[i] = strtod(ptr, &p);
        ptr = strtok(NULL, delim);
        i++;
    }


    return row;
}

void ffill1Dtab0 (double *tab, int dim) {
    for (int i = 0; i < dim; i++) {
        tab[i] = 0.0;
    }
}

void calcDInverse(double **tab, int dim) {
    for (int i=0; i<dim; i++)
        tab[i][i] = 1/tab[i][i];
}

void calcDInvXB(double **tab, double *b, int dim) {
    for (int i=0; i<dim; i++)
        b[i] *= tab[i][i];
}

void calcDInvLTab(double **inv, double **tab, int dim) {
    for (int i=0; i<dim; i++)
        for (int j=0; j<i; j++)
            tab[i][j] *= inv[i][i];

}

void calcDInvUTab(double **inv, double **tab, int dim) {
    for (int i=0; i<dim; i++)
        for (int j=i+1; j<dim; j++)
            tab[i][j] *= inv[i][i];
}


void calcEq(double *x, double *prevX, double *b, double **L, double **U, int dim, double epsilon, int *iter) {
    int satisfies = 0;
    while (!satisfies) {
        // calculations
        for (int i=0; i<dim; i++) {
            x[i] = b[i];                       // x = D^-1*b -
            for (int j=0; j<i; j++)
                x[i] -= L[i][j]*x[j];    // D^-1*L * x -
            for (int j=i+1; j<dim; j++)
                x[i] -= U[i][j]*x[j];    // D^-1*U * x
        }

        // first iteration - cannot calculate accuracy
        if (iter == 0) {
            for (int i = 0; i < dim; i++) {
                prevX[i] = x[i];
            }
            (*iter)++;
        } else { // other iterations, calculate if x satisfies desired accuracy
            satisfies = 1;
            for (int i = 0; i < dim; i++) {
                if (((double)(x[i] - prevX[i]) / x[i]) > epsilon) {
                    satisfies = 0;
                    break;
                }
            }

            if (satisfies == 0) {
                for (int i = 0; i < dim; i++) {
                    prevX[i] = x[i];
                }
            }
            (*iter)++;
        }

    }
}

