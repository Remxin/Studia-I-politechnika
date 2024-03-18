#include <iostream>
using namespace std;

template<class T1>
void display(T1 m, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void display(double *m, int w) {
    for (int i = 0; i < w; i++) {
        cout << m[i] << "\t";
    }
    cout << endl;
}



//
//
//int main() {
//    double m1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//    double m2[3] = {1,2,3};
//    display(m2, 3);
//    display(m1, 3, 3);
//    return 0;
//}