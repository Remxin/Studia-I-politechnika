

#include <stdio.h>

int input(char* text) {
    int num;
    printf(text);
    scanf("%d", &num);
    return num;
}

int main() {
    int a, b, c, d;
    a = input("Podaj a: ");
    b = input("Podaj b: ");
    c = input("Podaj c: ");
    d = input("Podaj d: ");

    if (a > b && a > c && a > d) {
        printf("Najwieksza liczba: %d, pozycja: %d", a, 1);
    } else if (b > a && b > c && b > d) {
        printf("Najwieksza liczba: %d, pozycja: %d", b, 2);
    } else if (c > a && c > b && c > d) {
        printf("Najwieksza liczba: %d, pozycja: %d", c, 3);
    } else if (d > a && d > b && d > c) {
        printf("Najwieksza liczba: %d, pozycja: %d", d, 4);
    }

    return 0;
}