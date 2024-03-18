#include <iostream>

template<class T1>
auto sumM(T1 *M, int n) -> T1 {
    T1 sum = 0;
    for (int i = 0; i < n; i++) {
        sum += M[i];
    }
    return sum;
}

//int main() {
//    double M[5] = { 1,2,3,4,5};
//    std::cout << sumM(M, 5);
//    return 0;
//}
