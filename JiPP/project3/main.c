
#include <printf.h>

extern void InitFiles();
extern void CloseFiles();
extern int getMatrixDim();
extern double **falloc2DMatrix(int n);
extern double *falloc1DMatrix(int n);
extern void ffree1DMatrix(double *tab);
extern void ffree2DMatrix(double **tab, int n);

extern double *get1Dmatrix(int n);
extern double **get2Dmatrix(int n);

extern void divideA(double **A, double **L, double **D, double **U, int dim);
extern void ffill1Dtab0 (double *tab, int dim);

extern void calcDInverse(double **tab, int dim);
extern void calcDInvXB(double **tab, double *b, int dim);
extern void calcDInvLTab(double **inv, double **tab, int dim);
extern void calcDInvUTab(double **inv, double **tab, int dim);

extern void calcEq(double *x, double *prevX, double *b, double **L, double **U, int dim, double epsilon, int *iter);
extern void writeResults(double *x,int dim, int iter);

extern void error(int nr, char *str);

int main() {
    InitFiles();
    int dim = getMatrixDim();
    double **A = get2Dmatrix(dim), **L = falloc2DMatrix(dim), **D = falloc2DMatrix(dim), **U = falloc2DMatrix(dim);
    double *b = get1Dmatrix(dim); // works
    double *x = falloc1DMatrix(dim), *prevX = falloc1DMatrix(dim);

    // divide A into L, D, U
    divideA(A, L, D, U, dim);

    // fill results tab nad prev result tab with 0
    ffill1Dtab0(x, dim);
    ffill1Dtab0(prevX, dim);

    // inverse tabs
    calcDInverse(D, dim);
    calcDInvXB(D, b, dim);
    calcDInvUTab(D, U, dim);
    calcDInvLTab(D, L, dim);


    // give desired accuracy
    double epsilon;
    printf("Podaj wymagana dokladnosc: ");
    if (scanf("%lf", &epsilon) != 1) error(5, "Dokladnosc powinna byc liczba rzeczywista");

    int iter = 0;
    // do the calculations
    calcEq(x, prevX, b, L, U, dim, epsilon, &iter);

    // display results + write them to file
    writeResults(x, dim, iter);

    // free the memory
    ffree1DMatrix(x);
    ffree1DMatrix(prevX);
    ffree1DMatrix(b);
    ffree2DMatrix(A, dim);
    ffree2DMatrix(L, dim);
    ffree2DMatrix(D, dim);
    ffree2DMatrix(U, dim);


    CloseFiles();
    return 0;
}


