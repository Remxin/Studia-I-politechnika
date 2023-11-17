#include <stdio.h>
#include <math.h>


int checkIfExists(double a, double b, double c) {
    double smallest, middle, largest;
    if (a < b && a < c) {
        smallest = a;
        if (b < c) {
            middle = b; largest = c;
        }
        else {
            middle = c; largest = b;
        }

    } else if (b < a && b < c) {
        smallest = b;
        if (a < c) {
            middle = a; largest = c;
        } else {
            middle = c; largest = a;
        }
    } else if (c < a && c < b) {
        smallest = c;
        if (a < b) {
            middle = a; largest = b;
        } else {
            middle = b; largest = a;
        }
    } else {
        return -1; // error

    }

    if (smallest + middle > largest) return 1;
    else return 0;
}

int main() {
    double a = 3.0, b = 5, c = 10;
    int exi = checkIfExists(a, b ,c);

    printf("Trojkat %s\n", exi == 0 ? "nie istnieje" : "istnieje");

    if (exi == 1) {
        double p = (a + b + c) / 2;
        double S = sqrt(p * (p - a) * (p - b) * (p - c));
        double R = S / p;

        printf("Pole trojkata: %lf\n", S);
        printf("Promien kola wpisanego w trojkat: %lf\n", R);
    }
    return 0;
}