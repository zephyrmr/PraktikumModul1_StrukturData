// Tipe Data Abstrak

#include <stdio.h>
// Definisi struktur Mahasiswa
struct Mahasiswa{
    const char *name; //pake pointer
    const char *address;
    int age;
};

int main(){
    // Deklarasi 2 variables menggunakan struct Mahasiswa
    struct Mahasiswa mhs1, mhs2;

    // Mengisi nilai ke dalam struct mhs1
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    // Mengisis nilai ke dalam struct mhs2
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}