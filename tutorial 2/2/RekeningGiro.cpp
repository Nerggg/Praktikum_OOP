#include "RekeningGiro.h"

RekeningGiro::RekeningGiro(double saldo, double bunga) : Rekening(saldo) {
    if (bunga < 0) {
        this->sukuBunga = 0;
    }
    else {
        this->sukuBunga = bunga;
    }
}

void RekeningGiro::setSukuBunga(double bunga) {
    this->sukuBunga = bunga;
}

double RekeningGiro::getSukuBunga() const {
    return this->sukuBunga;
}

double RekeningGiro::hitungBunga() {
    return this->sukuBunga*getSaldo();
}