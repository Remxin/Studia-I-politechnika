#include <iostream>
using namespace std;

int sT(int *p, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *p++;
    }
    return sum;
}

int main() {
    int tab[5] = { 1,2,3,4,5};
    cout << sT(tab, sizeof(tab) / sizeof(int));
    return 0;
}