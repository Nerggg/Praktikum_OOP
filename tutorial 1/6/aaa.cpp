#include "BigNumber.hpp"
using namespace std;

int main() {
    BigNumber a(999);
    BigNumber b(1239);
    BigNumber c(a+b);

    for (int i = c.getMaxDigit()-1; i >= 0; i--) {
        cout << c.digit[i];
    }
    cout << endl;

    for (int i = 0; i < c.getMaxDigit(); i++) {
        cout << c.digit[i];
    }
    cout << endl;

    if (a==b) {
        cout << "bener" << endl;
    }
}