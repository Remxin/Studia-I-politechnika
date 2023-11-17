#include <stdio.h>
#include <math.h>
#include <process.h>

#define PI 3.14

int checkIfTriangleExists(double a, double b, double c) {
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

double getValFromUser(char *text) {
    double num;
    printf(text);
    scanf("%lf", &num);

    if (num <= 0) {
        printf("Podano zla dlugosc boku\n");
        exit(-1);
    }

    return num;
}

double figureObw(double a, double b, double c, double d) {
    return a + b + c + d;
}

double triangleP(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    return S;
}

double squareP(double a) {
    return pow(a, 2);
}

double rectP(double a, double b) {
    return a * b;
}

double circleObw(double r) {
    return 2 * PI * r;
}

double circleP(double r) {
    return PI * pow(r, 2);
}

int main() {
    double a, b, c, d, r;

    int figureChoice = -1;
    printf("--- Wybierz figure: ---\n1. trojkat\n2. kwadrat\n3. prostokat\n4. kolo\n: ");
    scanf("%d", &figureChoice);

    switch(figureChoice) {
        case 1:
            printf("Wybrano trojkat\n");

            a = getValFromUser("Podaj a: ");
            b = getValFromUser("Podaj b: ");
            c = getValFromUser("Podaj c: ");

            int triangleExists = checkIfTriangleExists(a, b, c);
            printf("Podany trojkat %s\n", triangleExists == 1 ? "istnieje" : "nie istnieje");
            if (triangleExists == 0) break;
            printf("Obwod trojkata: %lf\n", figureObw(a, b, c, 0));
            printf("Pole trojkata: %lf\n", triangleP(a, b, c));
            break;
        case 2:
            printf("Wybrano kwadrat\n");
            a = getValFromUser("Podaj a: ");
            printf("Obwod kwadratu: %lf\n", figureObw(a, a, a, a));
            printf("Pole kwadratu: %lf\n", squareP(a));
            break;
        case 3:
            printf("Wybrano Prostokat\n");
            a = getValFromUser("Podaj a: ");
            b = getValFromUser("Podaj b: ");

            printf("Obwod prostokata: %lf\n", figureObw(a, b, a, b));
            printf("Pole prostokata: %lf\n", rectP(a, b));
            break;
        case 4:
            printf("Wybrano kolo\n");
            r = getValFromUser("Podaj r: ");


            printf("Obwod kola: %lf\n", circleObw(r));
            printf("Pole kola: %lf\n", circleP(r));
            break;
        default:
            printf("Wybrano zla figure");
            break;
    }
    return 0;
}
