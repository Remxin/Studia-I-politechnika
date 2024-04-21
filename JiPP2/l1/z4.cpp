#include <iostream>

using namespace std;

void printTab(int tab[3][3], int sizeC, int sizeR) {
    for (int i = 0; i < sizeC; i++) {
        for (int j = 0; j < sizeR; j++) {
            cout << i << ", " << j << ": " << tab[i][j] << endl;
        }
    }
}

void printTabZ(int tab[][3], int sizeC, int sizeR) {
    int *p;
    for (int i = 0; i < sizeC; i++) {
        p = tab[i];
        for (int j = 0; j < sizeR; j++) {
            cout << i << ", " << j << ": " << *p++ << endl;
        }
    }
}


int main() {
    int tab[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    int sizeC = sizeof(tab) / sizeof(tab[0]);
    int sizeR = sizeof(tab[0]) / sizeof(int);
//    printTab(tab, sizeC, sizeR);
    printTabZ(tab, sizeC, sizeR);
    return 0;
}
