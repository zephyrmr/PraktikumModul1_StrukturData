#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string Nama;
    int Umur;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void inisialisasi()
{
    head = NULL;
    tail = NULL;
}

// Cek Node
bool cekNode()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Add First
void addFirst(string name, int age)
{
    Node *baru = new Node;
    baru->Nama = name;
    baru->Umur = age;
    baru->next = NULL;

    if (cekNode() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Add Last
void addLast(string name, int age)
{
    Node *baru = new Node;
    baru->Nama = name;
    baru->Umur = age;
    baru->next = NULL;

    if (cekNode() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node dalam Linked List
int hitungNode()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Add Middle
void addMiddle(string name, int age, int posisi)
{
    if (posisi < 1 || posisi > hitungNode())
    {
        cout << "Posisi di luar jangkauan." << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah." << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->Nama = name;
        baru->Umur = age;

        // Tranversing (proses melintasi atau mengunjungi setiap elemen dalam struktur data)
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Delete First
void deleteFirst()
{
    Node *hapus;

    if (cekNode() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Kosong!" << endl;
    }
}

// Delete Last
void deleteLast()
{
    Node *hapus;
    Node *bantu;

    if (cekNode() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "Kosong!" << endl;
    }
}

// Delete Middle
void deleteMiddle(int posisi)
{
    Node *hapus, *bantu, *bantu2;

    if (posisi < 1 || posisi > hitungNode())
    {
        cout << "Posisi di luar jangkauan." << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah." << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }

            if (nomor == posisi)
            {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Change Fisrt
void changeFirst(string name, int age)
{
    if (cekNode() == false)
    {
        head->Nama = name;
        head->Umur = age;
    }
    else
    {
        cout << "Tidak ada perubahan data." << endl;
    }
}

// Change Middle
void changeMiddle(string name, int age, int posisi)
{
    Node *bantu;

    if (cekNode() == false)
    {
        if (posisi < 1 || posisi > hitungNode())
        {
            cout << "Posisi di luar jangkauan." << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah." << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }

            bantu->Nama = name;
            bantu->Umur
     = age;
        }
    }
    else
    {
        cout << "Tidak ada data." << endl;
    }
}

// Change Last
void changeLast(string name, int age)
{
    if (cekNode() == false)
    {
        tail->Nama = name;
        tail->Umur
 = age;
    }
    else
    {
        cout << "Tidak ada data." << endl;
    }
}

// Delete Node
void remove()
{
    Node *bantu, *hapus;
    bantu = head;

    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "Menghapus semua node" << endl;
}

// Tampilkan Linked List
void print()
{
    Node *bantu;
    bantu = head;

    cout << left << setw(15) << "     Nama  " << right << setw(4) << " Usia  " << endl; // Supaya rapi
    cout << "    ------    " << " ------"<< endl;

    if (cekNode() == false)
    {
        while (bantu != NULL)
        {
            cout << left << setw(15) << bantu->Nama << right << setw(4) << bantu->Umur
     << endl; // Supaya lurus di output
            bantu = bantu->next;
        }

        cout << endl;
    }
    else
    {
        cout << "Tidak ada data." << endl;
    }
}

int main()
{
    inisialisasi();         
    //Jawaban A                          
    cout << "\n// Tambahkan nama Anda" << endl; 
    addFirst("Karin", 18);
    addFirst("Hoshino", 18);
    addFirst("Akechi", 20);
    addFirst("Yusuke", 19);
    addFirst("Michael", 18);
    addFirst("Jane", 20);
    addFirst("John", 19);
    addFirst("Anisah Syifa", 18);
    print();

    // Jawaban B
    cout << "// Hapus data 'Akechi' " << endl;
    deleteMiddle(6);
    print();

    // Jawaban C
    cout << "// Tambah data 'Futaba (18)' di antara John & Jane" << endl;
    addMiddle("Futaba", 18, 3);
    print();

    // Jawaban D
    cout << "// Tambah data 'Igor (20)' di awal" << endl;
    addFirst("Igor", 20);
    print();

    // Jawaban E dan F
    cout << "// Ubah data 'Michael' menjadi 'Reyn (18)'" << endl;
    cout << "// Tampilan Akhir" << endl;
    changeMiddle("Reyn", 18, 6);
    print();

    return 0;
}