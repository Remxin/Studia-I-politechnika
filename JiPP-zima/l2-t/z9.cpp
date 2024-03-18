#include <iostream>

template<class T1>
auto getMax(T1 *M, int m) -> T1 {
    T1 max = -std::numeric_limits<double>::infinity();
    for (int i = 0; i < m; i++) {
        if (M[i] > max) max = M[i];
    }
    return max;
}


//int main() {
//    int M[5] = { 5,4,6,10,2 };
//    std::cout << getMax(M, 5);
//}
