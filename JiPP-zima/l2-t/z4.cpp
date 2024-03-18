#include <iostream>
using namespace std;
template<class T1, class T2>
auto larger(T1 x, T2 y) -> decltype(x+y)
{
    if (x > y) return x;
    return y;
}

//int main() {
//    cout << "larger: " << larger(5, 6.7) << endl;
//    return 0;
//}