#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Deklarasi Class Node 
class Node
{ 
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

// Deklarasi Class DoubleLinkedList 
class DoubleLinkedList
{ 
public:
    Node *head;
    Node *tail;
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Menambahkan produk ke dalam linked list di urutan atas
    void addFirstProduct(string namaProduk, int harga)
    { 
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }

    // Menghapus produk teratas pada linked list
    void removeFirstProduct()
    { 
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    // Mengubah data 
    bool changeProduct(string namaProdukLama, string namaProdukBaru, int hargaBaru)
    { 
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == namaProdukLama)
            {
                current->namaProduk = namaProdukBaru;
                current->harga = hargaBaru;
                return true;
            }
            current = current->next;
        }
        return false; // Mengembalikan false jika data produk tidak ditemukan
    }

    // Menambahkan data produk pada posisi tertentu
    void addFirstProductSpecificPosition(string namaProduk, int harga, int posisi)
    { 
        if (posisi < 1)
        {
            cout << "Posisi tidak valid." << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        if (posisi == 1)
        { // Jika posisi adalah 1 maka tambahkan data produk di depan linked list
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            head = newNode;
            return;
        }
        Node *current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i)
        { // Looping sampai posisi sebelum posisi yang diinginkan
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = newNode; 
            // Pointer prev node setelah current menunjuk ke newNode jika node setelah current tidak nullptr
        }
        else
        {
            tail = newNode;
        }
        current->next = newNode;
    }

    // Menghapus data  pada posisi tertentu
    void removeSpecificPosition(int posisi)
    { 
        if (posisi < 1 || head == nullptr)
        {
            cout << "Posisi tidak valid / list kosong. " << endl;
            return;
        }
        Node *current = head;
        if (posisi == 1)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete current;
            return;
        }
        for (int i = 1; current != nullptr && i < posisi; ++i)
        { // Looping sampai posisi yang diinginkan
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }

    // Menghapus semua data produk
    void removeAll()
    { 
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    
    // Menampilkan data 
    void print()
    { 
        Node *current = head;
        cout << "\n=== List Produk dan Harga ===" << endl;
        cout << left << setw(20) << "Nama Produk"
             << "Harga" << endl;
        while (current != nullptr)
        {
            cout << left << setw(20) << current->namaProduk << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoubleLinkedList list; // Deklarasi objek list dari class DoubleLinkedList

    list.addFirstProduct("Hanasui", 30000);
    list.addFirstProduct("Wardah", 50000);
    list.addFirstProduct("Skintific", 100000);
    list.addFirstProduct("Somethinc", 150000);
    list.addFirstProduct("Originote", 60000);

    list.print();

    while (true)
    {
        cout << "\nPilihan Menu: " << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int pilihan;
        cout << "Pilih Menu: ";
        cin >> pilihan;
        switch (pilihan)
        { 
        case 1:
        {
            string namaProduk;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> namaProduk;
            cout << "Masukkan harga: ";
            cin >> harga;
            list.addFirstProduct(namaProduk, harga); 
            cout << "Produk berhasil ditambahkan di posisi paling atas." << endl;
            list.print();
            break;
        }
        case 2:
        {
            list.removeFirstProduct(); 
            cout << "Produk paling atas berhasil dihapus." << endl;
            list.print();
            break;
        }
        case 3:
        {
            string namaProdukLama, namaProdukBaru;
            int hargaBaru;
            cout << "Input nama produk lama: ";
            cin >> namaProdukLama;
            cout << "Input nama produk baru: ";
            cin >> namaProdukBaru;
            cout << "Input harga baru: ";
            cin >> hargaBaru;
            bool updated = list.changeProduct(namaProdukLama, namaProdukBaru, hargaBaru); 
            if (!updated)
            {
                cout << "--Data produk tidak ditemukan--" << endl;
            }
            else
            {
                cout << "--Data berhasil diupdate--" << endl;
            }
            list.print();
            break;
        }
        case 4:
        {
            string namaProduk;
            int harga, position;
            cout << "Input nama produk: ";
            cin >> namaProduk;
            cout << "Input harga: ";
            cin >> harga;
            cout << "Input posisi: ";
            cin >> position;
            list.addFirstProductSpecificPosition (namaProduk, harga, position); 
            cout << "Produk berhasil ditambahkan pada posisi ke-" << position << endl;
            list.print();
            break;
        }
        case 5:
        {
            int position;
            cout << "Input posisi yang ingin dihapus: ";
            cin >> position;
            list.removeSpecificPosition(position); 
            list.print();
            break;
        }
        case 6:
        {
            list.removeAll(); 
            break;
        }
        case 7:
        {
            list.print(); 
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            cout << "Input Invalid" << endl;
            break;
        }
        }
    }
    return 0;
}