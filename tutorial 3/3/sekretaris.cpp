#include "sekretaris.h"
#include <iostream>
using namespace std;

Sekretaris::Sekretaris() {
    energi = ENERGI_MAX;
    tinta = TINTA_DEFAULT;
    kertas = KERTAS_DEFAULT;
    memoLength = 0;
    memo = new Memo[memoLength];
}

Sekretaris::Sekretaris(int kertas, int tinta) {
    energi = ENERGI_MAX;
    tinta = tinta;
    kertas = kertas;
    memoLength = 0;
    memo = new Memo[memoLength];
}

Sekretaris::~Sekretaris() {}

void Sekretaris::buatMemo(string pesan, string untuk) {
    try {
        Memo newMemo(pesan, untuk);
        pakaiKertas();
        pakaiEnergi();
        pakaiTinta(pesan.length());
        
        Memo* temp = new Memo[memoLength+1];
        for (int i = 0; i < memoLength; i++) {
            temp[i] = memo[i];
        }
        memoLength++;
        temp[memoLength-1] = newMemo;
        delete[] memo;
        memo = temp;
        cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
    }
    catch(KertasHabisException e) {
        cout << e.what() << ", segera isi kertas" << endl;
    }
    catch(TintaKurangException e) {
        cout << e.what() << ", segera isi tinta" << endl;
        batalPakaiKertas();
    }
    catch(EnergiHabisException e) {
        cout << e.what() << ", segera istirahat" << endl;
        batalPakaiTinta(pesan.length());
        batalPakaiKertas();
    }
    catch(PesanKepanjanganException e) {
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
        batalPakaiEnergi();
        cout << e.what() << ", perpendek pesannya" << endl;
    }
}

void Sekretaris::pakaiKertas(){
    if(this->kertas <= 0){
        throw KertasHabisException();
    }
    this->kertas--;
}

void Sekretaris::pakaiTinta(int num){
    if(this->tinta < num){
        throw TintaKurangException();
    }
    this->tinta -= num;
}

void Sekretaris::pakaiEnergi(){
    if(energi <= 0){
        throw EnergiHabisException();
    }
    this->energi--;
}

void Sekretaris::batalPakaiKertas(){
    this->kertas++;
}

void Sekretaris::batalPakaiTinta(int num){
    this->tinta += num;
}

void Sekretaris::batalPakaiEnergi(){
    this->energi++;
}

void Sekretaris::isiTinta(int num){
    this->tinta += num;
}

void Sekretaris::isiKertas(int num){
    this->kertas += num;
}

void Sekretaris::istirahat(){
    this->energi = ENERGI_MAX;
}

void Sekretaris::printStatus(){
    cout << "Status" << endl;
    cout << "  Energi : " << energi << endl;
    cout << "  Tinta : " << tinta << endl;
    cout << "  Kertas : " << kertas << endl;
    cout << "  Memo : " << memoLength << endl;
    for(int i = 0; i < memoLength; i++){
        cout << "    Memo [" << i+1 << "]" << endl;
        cout << "      Pesan : " << memo[i].getPesan() << endl;
        cout << "      Untuk : " << memo[i].getUntuk() << endl;
    }
}