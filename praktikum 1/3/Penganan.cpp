#include "Penganan.hpp"
#include <iostream>

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

Penganan::Penganan() {
    this->keik = 0;
    this->panekuk = 0;
}

Penganan::Penganan(int keik, int panekuk) {
    this->keik = keik;
    this->panekuk = panekuk;
}

int Penganan::GetKeik() const {
    return this->keik;
}

int Penganan::GetPanekuk() const {
    return this->panekuk;
}

void Penganan::SetKeik(int k) {
    this->keik = k;
}

void Penganan::SetPanekuk(int p) {
    this->panekuk = p;
}

Penganan operator+(const Penganan& a, const Penganan& b) {
    Penganan c;
    c.keik = a.keik + b.keik;
    c.panekuk = a.panekuk + b.panekuk;
    Penganan::n_rumah++;
    return c;
}

Penganan operator-(const Penganan& stok, const Penganan& permintaan) {
    Penganan sisa;
    if (stok.keik > permintaan.keik) {
        sisa.keik = stok.keik - permintaan.keik;
        Penganan::uang += permintaan.keik * 51;
    }
    else {
        sisa.keik = 0;
        Penganan::uang += stok.keik * 51;
    }

    if (stok.panekuk > permintaan.panekuk) {
        sisa.panekuk = stok.panekuk - permintaan.panekuk;
        Penganan::uang += permintaan.panekuk * 37;
    }
    else {
        sisa.panekuk = 0;
        Penganan::uang += stok.panekuk * 37;
    }
    return sisa;
}

Penganan operator^(const Penganan& stok, const int sumbang) {
    Penganan sisa;
    if (stok.keik < sumbang) {
        sisa.keik = 0;
        Penganan::uang -= (sumbang - stok.keik) * 51;
    }
    else {
        sisa.keik = stok.keik - sumbang;
    }
    if (stok.panekuk < sumbang) {
        sisa.panekuk = 0;
        Penganan::uang -= (sumbang - stok.panekuk) * 37;
    }
    else {
        sisa.panekuk = stok.panekuk - sumbang;
    }
    return sisa;
}

Penganan operator^(const int sumbang, const Penganan& stok) {
    Penganan sisa;
    if (stok.keik < sumbang) {
        sisa.keik = 0;
        Penganan::uang -= (sumbang - stok.keik) * 51;
    }
    else {
        sisa.keik = stok.keik - sumbang;
    }
    if (stok.panekuk < sumbang) {
        sisa.panekuk = 0;
        Penganan::uang -= (sumbang - stok.panekuk) * 37;
    }
    else {
        sisa.panekuk = stok.panekuk - sumbang;
    }
    return sisa;
}

int Penganan::JumlahUang() {
    return Penganan::uang;
}

int Penganan::HitungNRumah() {
    return Penganan::n_rumah;
}

void Penganan::Print() {
    std::cout << this->keik << "keik-" << this->panekuk << "panekuk" << std::endl; 
}