#include <iostream>
using namespace std;

template <class T1, class T2>
void swap(T1 *x, T2 *y)
{
    T1 temp = *x;
    *x = *y;
    *y = temp;
}

//int main() {
//    double a = 7.3, b = 9.2;
//    swap(&a, &b);
//    cout << a << b << endl;
//    return 0;
//}