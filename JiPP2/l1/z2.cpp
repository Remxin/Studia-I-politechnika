#include <iostream>
#include <cmath>
using namespace std;

void logarytmFor(int tab[5], int size) {
    cout << "Logarytm for:\n";
    for (int i = 0; i < size; i++) {
        cout << "element " << i << ": " << log10(tab[i]) << endl;
    }
    cout << "\n\n";
}

void logarytmForZ(int tab[5], int size) {
    int *p = tab;
    cout << "Logarytm for + znacznik:\n";
    for (int i = 0; i < size; i++) {
        cout << "element " << i << ": " << log10(*p++) << endl;
    }
}

void logarytmWhile(int tab[5], int size) {
    int i = 0;
    cout << "Logarytm while:\n";
    while (i < size) {
        cout << "element " << i << ": " << log10(tab[i++]) << endl;
    }
}

void logarytmWhileZ(int tab[5], int size) {
    int *p = tab;
    int i = 0;
    cout << "Logarytm while + znacznik:\n";
    while (i < size) {
        cout  << log10(*p++) << endl;
        i++;
    }
}

int main() {
    int tab[5] = {1,2,3,10,100};
    int n = sizeof(tab) / sizeof(int);
    logarytmFor(tab, n);
    logarytmForZ(tab, n);
    logarytmWhile(tab, n);
    logarytmWhileZ(tab, n);
    return 0;
}