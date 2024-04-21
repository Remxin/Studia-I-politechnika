#include <iostream>

void multiAdd(int *num, int k, int num2) {
    for (int i = 0; i < k; i++) {
        *num += num2;
    }
}

//int main() {
//    int a = 1;
//    multiAdd(&a, 5, 10);
//    std::cout << a;
//}