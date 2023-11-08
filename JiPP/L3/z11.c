#include <printf.h>

void fun(double x, double y, double *wynik, int *nr) {
    double war1 = x*x + y*y;
    double war2 = x + 5;

    if (war1 <= 1) {
        *nr = 1;
        *wynik = x*x + y;
    } else if (y > war2) {
        *nr = 2;
        *wynik = 2*x + y*y;
    } else if (war1 > 1 && war2>=y) {
        *nr = 3;
        *wynik = .5*x*x + y;
    } else {
        *nr = -1;
        *wynik = 0;
    }
}

int main() {
    double x = 2., y = 5., wynik;
    int nr;

    fun(x, y, &wynik, &nr);

    printf("Numer operacji to %d\nWynik operacji: %lf\n", nr, wynik);

    return 0;
}
