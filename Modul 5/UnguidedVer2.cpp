#include <iostream>
#include <list>

using namespace std;

// class untuk menyimpan data mahasiswa
class Mahasiswa {
public:
    long long NIM;
    int nilai;
};

// class untuk hash table
class HashTable {
private:
    static const int tableSize = 10;
    list<Mahasiswa> table[tableSize];

public:
    // hash function untuk NIM
    int hashFunction(long long NIM) {
        return NIM % tableSize;
    }

    // fungsi untuk menambahkan data mahasiswa ke hash table
    void addData(long long NIM, int nilai) {
        int index = hashFunction(NIM);
        Mahasiswa mhs;
        mhs.NIM = NIM;
        mhs.nilai = nilai;
        table[index].push_back(mhs);
    }

    // fungsi untuk mencari data mahasiswa berdasarkan NIM
    void searchDataByNIM(long long NIM) {
        int index = hashFunction(NIM);
        bool found = false;
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->NIM == NIM) {
                cout << "Data mahasiswa dengan NIM " << NIM << " ditemukan.\n";
                cout << "Nilai: " << it->nilai << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
        }
    }

    // fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void searchDataByRange() {
        bool found = false;
        for (int i = 0; i < tableSize; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                if (it->nilai >= 80 && it->nilai <= 90) {
                    if (!found) {
                        cout << "Data mahasiswa dengan nilai antara 80 dan 90:\n";
                        found = true;
                    }
                    cout << "NIM: " << it->NIM << ", nilai: " << it->nilai << "\n";
                }
            }
        }
        if (!found) {
            cout << "Tidak ada data mahasiswa dengan nilai antara 80 dan 90.\n";
        }
    }

    // fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void deleteData(long long NIM) {
        int index = hashFunction(NIM);
        bool found = false;
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == NIM) {
                table[index].erase(it);
                cout << "Data mahasiswa dengan NIM " << NIM << " berhasil dihapus.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data mahasiswa dengan NIM " << NIM << " tidak ditemukan.\n";
        }
    }

    // fungsi untuk menampilkan data yang tersimpan
    void print() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                cout << "[" << pair.NIM << ", " << pair.nilai << "]";
            }
            cout << endl;
        }
    }
};

int main() {
    char ulang;
    HashTable hashTable;
    int choice, nilai;
    long long NIM;
    do {
        cout << "========================================\n";
        cout << "           MENU DATA MAHASISWA:\n";
        cout << "========================================\n";
        cout << "1. Tambah Data \n";
        cout << "2. Cari data berdasarkan NIM\n";
        cout << "3. Cari data berdasarkan nilai (80 - 90)\n";
        cout << "4. Hapus Data \n";
        cout << "5. Tampilkan Data \n";
        cout << "\nPilih menu: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Masukkan NIM : ";
                cin >> NIM;

                cout << "Masukkan Nilai : ";
                cin >> nilai;
                hashTable.addData(NIM, nilai);
                break;
            }
            case 2: {
                cout << "Masukkan NIM : ";
                cin >> NIM;
                hashTable.searchDataByNIM(NIM);
                break;
            }
            case 3: {
                hashTable.searchDataByRange();
                break;
            }
            case 4: {
                cout << "Masukkan NIM : ";
                cin >> NIM;
                hashTable.deleteData(NIM);
                break;
            }
            case 5: {
                hashTable.print();
                break;
            }
            default:
                break;
        }
        cout << "Lanjutkan memilih?(y/n)";
        cin >> ulang;
    } while (ulang == 'y');
    return 0;
}
