#include <math.h>
#include <stdio.h>
typedef struct CO {
    double re;
    double im;
} COMPLEX;

void calc (double a, double b, double c, struct CO *x1, struct CO *x2);
void dodaj(struct CO *x1, struct CO *x2, struct CO *x3);




int main() {
    double a=1, b=2, c=3;
    COMPLEX x1, x2, x3;
    calc(a,b,c,&x1,&x2);
    dodaj(&x1, &x2, &x3);

    printf("\nwynik dodawania: %lf + %lfi", x3.re, x3.im);

    return 0;
}

void calc (double a, double b, double c, struct CO *x1, struct CO *x2) {
    double d = b*b - 4*a*c;
    if (d >= 0) {
        x1->re = (-b + d) / (2*a);
        x1->im = 0;
        x2->re = (-b - d) / (2*a);
        x2->im = 0;
    } else {
        x1->re = -b / (2*a);
        x2->re = -b / (2*a);

        x1->im = sqrt(fabs(pow(b/(2*a), 2) - c/a));
        x2->im = -sqrt(fabs(pow(b/(2*a), 2) - c/a));
    }

    printf("Pierwiastki rownania:\n1) %lf + %lfi\n2) %lf + %lfi", x1->re, x1->im, x2->re, x2->im);
}


void dodaj(struct CO *x1, struct CO *x2, struct CO *x3) {
    x3->re = x1->re + x2->re;
    x3->im = x1->im + x2->im;
}

struct CO dodaj3(struct CO *x1, struct CO *x2) {

}