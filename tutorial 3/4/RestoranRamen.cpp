#include "RestoranRamen.hpp"

void RestoranRamen::tambahOrder(int n, int p) {
    daftarMeja[n] += p;
}

int RestoranRamen::tutupOrder(int n) {
    int temp = daftarMeja[n];
    daftarMeja.erase(n);
    return temp;
}

int RestoranRamen::cekTotal(int n) {
    return daftarMeja[n];
}

int RestoranRamen::totalMeja() {
    return daftarMeja.size();
}

void RestoranRamen::cetakMeja() {
    if (daftarMeja.size() == 0) {
        cout << "Restoran kosong" << endl;
    }
    else {
        for (map<int,int>::iterator itr = daftarMeja.begin(); itr != daftarMeja.end(); itr++) {
            cout << "Meja " << itr->first << " = " << itr->second << endl;
        }
    }
}