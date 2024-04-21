#include <iostream>

template<class T1, class T2>
auto sum2M(T1 *M1, int n1, T2 *M2, int n2) -> decltype(M1[0]+M2[0]) {
    int i = 0;
    decltype(M1[0]+M2[0]) sum = 0;
    for (;i < n1; i++) {
        sum += M1[i];
        if (i < n2) sum += M2[i];
    }
    for (;i < n2; i++) {
        sum += M2[i];
    }

    return sum;
}

int main() {
    int M1[4] = { 1,2,3,4};
    double M2[5] = { 1.1,2.3,2.3,2.3,4.5};
    std::cout << sum2M(M1, 4, M2, 5);
    return 0;
}
