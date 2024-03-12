//Contoh program menggunakan fungsi class dan struct

#include <iostream>
#include <string>

using namespace std;

class perlengkapan {
    public:
        string barang;
        int jumlah;
        float berat;
};

struct milik{
        string pemilikperlengkapan;
};

int main (){
    perlengkapan camping;
    perlengkapan bekerdja;
    milik pemilik1;
    milik pemilik2;

    camping.barang ="Tenda";
    camping.jumlah = 2;
    camping.berat  = 2.34;
    pemilik1.pemilikperlengkapan ="Anisah";


    bekerdja.barang ="Laptop";
    bekerdja.jumlah = 1;
    bekerdja.berat  = 1.88;
    pemilik2.pemilikperlengkapan ="Syifa";

    cout << "Perlengakpan untuk camping:" << endl;
    cout << "Nama perlengkapan: " << camping.barang<< endl;
    cout << "Jumlah: " << camping.jumlah <<endl;
    cout << "Berat: " << camping.berat << "kg" <<endl;
    cout << "Milik: " << pemilik1.pemilikperlengkapan <<endl;
    cout << endl;
    cout << "Perlengakpan untuk bekerja:" << endl;
    cout << "Nama perlengkapan: " << bekerdja.barang<< endl;
    cout << "Jumlah: " << bekerdja.jumlah <<endl;
    cout << "Berat: " << bekerdja.berat << "kg" <<endl;
    cout << "Milik: " << pemilik2.pemilikperlengkapan <<endl;

    return 0;
} 