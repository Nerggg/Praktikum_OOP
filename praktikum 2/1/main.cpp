#include "A.hpp"
#include "B.hpp"

int main() {
    B b;

    b.A::setMe(10);
    b.setMe(200);
    b.print();
    return 0;
}
