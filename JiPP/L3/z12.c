#include <stdio.h>

long liczSuma(long *suma, int n) {
    if (n == 0) return *suma;
    else {
        *suma += n;
        liczSuma(suma, n - 1);
    }
}

int main() {
    int n;
    long suma = 0;
    printf("Podaj liczbe n do wyznaczenia sumy: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Podano zla liczbe n\n zakonczenie programu");
        return 0;
    }

    liczSuma(&suma, n);

    printf("Suma wynosi %ld", suma);

    return 0;
}