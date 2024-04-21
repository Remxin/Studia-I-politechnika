#include <iostream>
using namespace std;

int add(int a, int b) {
    return a+b;
}

double add(double a, double b) {
    return a+b;
}

double add(double a, int b) {
    return a+b;
}

double *add(double *a, double *b, int w) {
    double *ret = new double [w];
    for (int i = 0; i < w; i++) {
        ret[i] = a[i] + b[i];
    }
    return ret;
}

double **add(double **a, double **b, int w, int h) {
    double **ret = new double *[h];
    for (int i = 0; i < h; i++) {
        ret[i] = new double [w];
        for (int j = 0; j < w; j++) {
            ret[i][j] = a[i][j] + b[i][j];
        }
    }

    return ret;
}

int main() {
    return 0;
}
