#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
string add(T1 a, T2 b) {
    string res = a + b;
    return res;
}

//int main() {
//    string s1 = "aaa";
//    string s2 = "bbb";
//    cout << add(s1, s2);
//    return 0;
//}