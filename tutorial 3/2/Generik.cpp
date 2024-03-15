#include <iostream> 
using namespace std;

template <class P>
void func(P a, P b) {
    cout << "Masukan Anda: " << a << " dan " << b << ", memiliki tipe yang sama" << endl;
}

template <class P, class Q>
void func(P a, Q b) {
    cout << "Masukan Anda: " << a << " dan " << b << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func(char a, int b) {
    for (int i = 0; i < b; i++) {
        cout << a << endl;
    }
}