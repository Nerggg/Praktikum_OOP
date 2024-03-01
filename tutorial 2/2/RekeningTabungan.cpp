#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biaya) : Rekening(saldo) {
    if (biaya < 0) {
        this->biayaTransaksi = 0;
    }
    else {
        this->biayaTransaksi = biaya;
    }
}

void RekeningTabungan::setBiayaTransaksi(double biaya) {
    this->biayaTransaksi = biaya;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return this->biayaTransaksi;
}

void RekeningTabungan::simpanUang(double uang) {
    Rekening::simpanUang(uang - this->biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double uang) {
    bool flag = Rekening::tarikUang(uang);
    if (flag) {
        Rekening::simpanUang(-this->biayaTransaksi);
    }
    return flag;
}