#include <iostream>
using namespace std;

template<class T1, class T2>
auto substr(T1 x, T2 y) -> decltype(x+y)
{
    return x - y;
}

//int main() {
//    cout << "roznica: " << substr(5.2, 3) << endl;
//    return 0;
//}

