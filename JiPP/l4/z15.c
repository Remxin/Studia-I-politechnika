#include <math.h>
#include <stdio.h>

double ff(double x) {
    return 1 / (x*x + sqrt(1 + 2*x + 3*x*x));
}

int main() {
    FILE *fw;
    if (!(fw = fopen("wyniki.txt", "w"))) return -2;
    double a, b;
    int k;
    if (scanf("%lf", &a) != 1) return -1;
    if (scanf("%lf", &b) != 1) return -1;
    if (scanf("%d", &k) != 1) return -1;
    double skok = (b - a) / k;
    double krok = a;
    while (krok < b) {
        double wynik = ff(skok);
        fprintf(fw, "\t%10.2lf\t\t%15.4lf\n", skok, wynik);
        printf("\t%10.2lf\t\t%15.4lf\n", skok, wynik);
        krok += skok;
    }


    return 0;
}
