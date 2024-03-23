//Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.

#include <iostream>
using namespace std;
    

    void hasilPilihan (char pilihan) {
        if (pilihan == 'A'|| pilihan == 'a') {
        cout << "Selamat menjalani hari Anda. Semoga Anda selalu diberikan kebahagiaan.";
        }else if(pilihan == 'B'|| pilihan == 'b'){
        cout << "Ayo ceritakan hari Anda, kami siap memberi kamu saran hari ini." <<endl << "Hubungi nomor yang tertera pada halaman profile Saranhariini.id";
        }else {
        cout << "Pilihan Anda tidak valid.";
        }
    }

int main () {
    char pilihan;
    cout <<"==-==========================================="<<endl;
    cout <<"Halo Selamat Datang di Website Saranhariini.id" <<endl; 
    cout <<"=============================================="<<endl;
    cout << "Apa perasaanmu hari ini?..." <<endl;
    cout << "A. Baik" <<endl << "B. Tidak baik"<< endl;
    cout << "tekan A atau B:...";
    cin >> pilihan;

    hasilPilihan (pilihan);
    return 0;
}