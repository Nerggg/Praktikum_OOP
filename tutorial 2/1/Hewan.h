#include <iostream>

using namespace std;

class Hewan {
	protected:
		string nama;
    public:
        Hewan(string nama);
        ~Hewan();
        virtual void print();
};

class Kucing : public Hewan {
    public:
        Kucing(string nama);
        virtual ~Kucing();
        // void print();
};

class Anjing : public Hewan {
    public:
        Anjing(string nama);
        ~Anjing();
        void print();
};

class KucingAnggora : public Kucing {
    protected:
        string pemilik;
    public:
        KucingAnggora(string nama, string pemilik);
        ~KucingAnggora();
        void print();
};

class AnjingBulldog : public Anjing {
    protected:
        string pemilik;
    public:
        AnjingBulldog(string nama, string pemilik);
        ~AnjingBulldog();
        void print();
};

inline void Hewan::print() {
    cout << "Hewan ini namanya " << this->nama << endl;
}

// inline void Kucing::print() {
//     // Hewan::print();
//     cout << "Kucing ini namanya " << this->nama << endl;
// }

inline void Anjing::print() {
    // Hewan::print();
    cout << "Anjing ini namanya " << this->nama << endl;
}

inline void KucingAnggora::print() {
    // Kucing::print();
    cout << "Kucing anggora ini namanya " << this->nama << ". Pemiliknya adalah " << this->pemilik << endl;
}

inline void AnjingBulldog::print() {
    // Anjing::print();
    cout << "Anjing bulldog ini namanya " << this->nama << ". Pemiliknya adalah " << this->pemilik << endl;
}

inline Hewan::~Hewan() {
    cout << "Hewan mati " << this->nama << endl;
}

inline Hewan::Hewan(string n) : nama(n) {}

inline Kucing::Kucing(string n) : Hewan(n) {}

inline Kucing::~Kucing() {
    cout << "Kucing mati " << this->nama << endl;
}

inline Anjing::Anjing(string n) : Hewan(n) {}

inline Anjing::~Anjing() {
    cout << "Anjing mati " << this->nama << endl;
}

inline KucingAnggora::KucingAnggora(string n, string p) : Kucing(n), pemilik(p) {}

inline KucingAnggora::~KucingAnggora() {
    cout << "Kucing anggora mati " << this->nama << endl;
}

inline AnjingBulldog::AnjingBulldog(string n, string p) : Anjing(n), pemilik(p) {}

inline AnjingBulldog::~AnjingBulldog() {
    cout << "Anjing bulldog mati " << this->nama << endl;
}