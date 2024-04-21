#include <iostream>

using namespace std;

int silnia_iter(int n) {
    int wynik = 1;
    for (int i = 1; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

int silnia_rek(int n) {
    if (n == 0) return 1;
    else return n*silnia_rek(n-1);
}

int potega_iter(int n, int pot) {
    int wynik = 1;
    for (int i = 1; i <= pot; i++) {
        wynik *= n;
    }
    return wynik;
}

int potega_rek(int n, int pot) {
    if (pot == 0) return 1;
    else return n * potega_rek(n, pot-1);

}

int fib_iter(int n) {
    if (n < 1) return -1;
    else if (n < 2) return 1;

    int prev = 0, curr = 1, wynik;
    for (int i = 2; i <= n; i++) {
        wynik = prev + curr;
        prev = curr;
        curr = wynik;
    }
    return wynik;
}

int fib_rekur(int n) {
    if (n < 3) return 1;
    else return fib_rekur(n-1) + fib_rekur(n-2);
}

int isPrimary(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main () {
    int n, pot, fib, prim;
//    cout << "Podaj liczbe: ";
//    cin >> n;
//    cout << "silnia iter: " << silnia_iter(n) << endl;
//    cout << "silnia rek: " << silnia_rek(n) << endl << "Podaj potege: ";
//    cin >> pot;
//    cout << "potega iter: " << potega_iter(n, pot) << endl;
//    cout << "potega rekur: " << potega_rek(n, pot) << endl;

    cout << "Podaj element ciagu fibbonacciego: ";
    cin >> fib;
    cout << "fib iter: " << fib_iter(fib) << endl;
    cout << "fib rekur: " << fib_rekur(fib) << endl;

//    cout << "Podaj liczbe do sprawdzenia, czy jest pierwsza:";
//    cin >> prim;
//    cout << "Jest (1), nie (0): " << isPrimary(prim) << endl;



}