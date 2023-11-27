//
// Created by poczt on 10/12/2023.
//

#include <stdio.h>
#include <math.h>

double w1(double x, double y, double z) {
    return pow(x / (y*z), 1./3) * log(pow(x, 2) + pow(y, 2));
}

double w2(int k, int m, double x, double y) {
    return sin(k * (x / 2)) * cos(m * y) + y*exp(2*x - 1);
}

double w3(double x, double y, double z) {
    return fabs(x / (2 * pow(y, 2) + 1)) + sqrt(y / (pow(z, 2) + 3)) + 5*pow(y + z, 3);
}

double w4(double x, double y, double z, int k) {
    return x / (y * z) * pow(z + 1, 1./3) + pow(pow(x, 2) + pow(z, 2) + 1, 1./k) - fabs(y);
}

double w5(double x, double y, double z, int k) {
    return 1 / sqrt(pow(x, 2) + pow(y, 2) + pow(k, 2)) + 1/x*sin(k * y);
}

int main() {
    double x = 3.14, y = 12.56, z = 7.0;
    int k = 2, m = 4;


    printf("Wynik w1: %.8lf\n", w1(x, y, z));
    printf("Wynik w2: %.8lf\n", w2(k, m, x, y));
    printf("Wynik w3: %.8lf\n", w3(x, y , z));
    printf("Wynik w4: %.8lf\n", w4(x, y , z, k));
    printf("Wynik w5: %.8lf\n", w5(x, y , z, k));
    return 0;
}