#include "Rekening.h"

Rekening::Rekening(double saldo) {
    if (saldo < 0) {
        this->saldo = 0;
    }
    else {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double saldo) {
    this->saldo = saldo;
}

double Rekening::getSaldo() const {
    return this->saldo;
}

void Rekening::simpanUang(double uang) {
    this->saldo += uang;
}

bool Rekening::tarikUang(double uang) {
    if (uang > this->saldo) {
        return false;
    }
    else {
        this->saldo -= uang;
        return true;
    }
}