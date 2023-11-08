

#include <stdio.h>

#define PI 3.1415

void kolo(double r, double *w1, double *w2) {
    *w1 = 2*PI*r;
    *w2 = PI*r*r;
}

int main() {
    double r = 4, w1, w2;
    kolo(r, &w1, &w2);

    printf("Obwod kola: %lf\nPole kola: %lf\n", w1, w2);

    return 0;
}
