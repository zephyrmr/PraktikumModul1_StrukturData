// SINGLE LINKED LIST NON-CIRCULAR

#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    int data;// menyimpan nilai yang diberikan kepada node saat node tersebut dibuat.
    Node *next;//pointer yang menunjuk ke node berikutnya
};

Node *head;
Node *tail;

// Inisialisasi Node
void init()
{
    head = NULL; // jadi head dan tail bernilai kosong
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty()
{
    return head == NULL;
} // memeriksa apakah linked list kosong atau tidak. Jika head bernilai NULL, maka dianggap linked list kosong dan fungsi akan mengembalikan true

// Tambah Node di depan
void insertDepan(int nilai)//int nilai adalah parameter yang memungkinkan Anda untuk menentukan nilai apa yang akan dimasukkan ke dalam node baru saat menggunakan fungsi insertDepan(). Berarti di sini nilai yang dimasukkan harus integer
{
    Node *baru = new Node;//membuat pointer baru yang menunjuk ke sebuah objek Node baru. Objel tersebut, sesuai struct, akan memiliki 2 anggota yaitu data dan next. New itu operator btw.
    baru->data = nilai;//nilai data dari node baru akan berisi nilai yang diberikan parameter prosedur. 
    baru->next = NULL;//pointer next dari node baru menjadi NULL. Karena node baru akan dimasukkan di depan linked list, maka node baru tersebut akan menjadi elemen pertama, sehingga pointer next-nya tidak menunjuk ke node lain.
    if (isEmpty())
    {
        head = tail = baru;
    }   //kalo kosong makan akan menjadi satu- satunya node dalam linked list. 
    else
    {
        baru->next = head;
        head = baru;
    }//kalo engga maka akan ditambahkan di depan node yang telah ada, dan head di pindah ke node baru
}

// Tambah Node di belakang
void insertBelakang(int nilai)
{
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }   //node baru ditambahkan setelah node paling belakang, dan menjadi tail. 
}

// Hitung jumlah Node di list
int hitungList()//parameter bersifat opsional.Jika fungsi itu membutuhkan input, maka kita harus membuatkan parameter.
{ 
    Node *hitung = head;//terdapat node baru yang memiliki pointer hitung, node tersebut adalah head (berada di palig awal)
    int jumlah = 0;//jumlah awal adalah 0
    while (hitung != NULL)
    {
        jumlah++;//tiap iterasi akan bertambah 1
        hitung = hitung->next;//Pada setiap iterasi loop, pointer hitung akan diarahkan ke node berikutnya dalam linked list dengan mengakses pointer next
    }
    return jumlah;
}

// Tambah Node di posisi tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru = new Node();//()penggunaannya opsional, defaultnya aja gitu, cuma gaya penulisan, bukan fungsi. 
        baru->data = data;
        Node *bantu = head;//Membuat pointer bantu yang menunjuk ke node pertama dari linked list. Atau anggap aja ini tu salinannya head, biasanya namanya cur kalo di ytb. 
        int nomor = 1;//untuk melacak posisi saat ini dalam linked list.
        while (nomor < posisi - 1)//misal mau disisipkan di antar anode 2 dan 3 ya berarti posisis-1=2.
        {
            bantu = bantu->next;//kalo nomor masih memenuhi berarti bantu yang tadinya sama dengan head, ya berarti menunjuk terus(bantu next) sampai tidak memenuhi. 

            nomor++;
        }//nah kalo udah selesai bantu nya sekarang kan berada di antara node yang mau disisipin kan, atau anggap aja sebelum posisi -1. 
        baru->next = bantu->next;//next pada baru disamaan dengan next pada bantu, jadi sekarang menunjuk node yang sama. Menunjuk ke node sebelah kanan yang akan disisipi. 
        bantu->next = baru; //next dari bantu sekarang adalah node baru. Jadi bantu yang tadinya ada 2 duplikat yaitu yang satunya node seblah kiri sebelum disisipi, maka keduanya sekarang menunjuk ke node baru. 
    }
}//https://youtu.be/ujXmAcDnSjc?si=oOpdeusrNhcZr2l8

//kenapa sih cur atau biasanya duplikat dari suatu node tertentu kalo ada yang dirubah maka berubah dua duanya? ya karena memiliki pointer yang sama, alamat yang sama. 
// Hapus Node di depan
void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;//duplikat head(bayangkan ada node duplikat di bawah node head).
        if (head->next != NULL)
        {
            head = head->next;
            delete hapus;//sama aja yang dihapus itu head yang sebelum dipindah ke node kedua karena hapus masih menunjuk ke head sebelumnya, dan head yang sekarang node kedua tidak dihapus. 
        }
        else
        {
            head = tail = NULL;
            delete hapus;// kalo cuma ada satu node maka di hapus langsung
        }
    }
    else
      {//kalo listnya kosong makan akan ditampilkan pesan ini.
        cout << "List kosong!" << endl;
    }
}//https://youtu.be/VVemCxif9vg?si=nxRVbZOzIQLpn21v

// Hapus Node di belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        if (head != tail)
        {
            Node *hapus = tail;
            Node *bantu = head;
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
        cout << "List kosong!" << endl;
    }
}//sudah bisa dan pernah  diilustrasikan sendiri.

// Hapus Node di posisi tengah
void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++)
        {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        //jadi node bantu itu nextnya menuju ke tail atau sama saja menuju ke hapus next(node terakhir), jadi node tengah diantara bantu dan hapus next itu tidak ditunjuk, maka dari itu dihapus. 
        delete hapus;
    }
}

// Ubah data Node di depan
void ubahDepan(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di posisi tengah
//https://youtu.be/ujXmAcDnSjc?si=s_oGZOMgr2JRKbDI
void ubahTengah(int data, int posisi)
{ 
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
            //ini berarti bantu next nya nanti ada di node yang kita cari, jadi kalo misalnya cari 4 ya bererti nanti bantu next nya ada di node 4.
                bantu = bantu->next;
            }
            bantu->data = data;
            //isi datanya sama karena pointernya juga sama jadi nilainya sama. 
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah data Node di belakang
void ubahBelakang(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua Node di list
void clearList()
{
    Node *bantu = head;
    while (bantu != NULL)
    {
        Node *hapus = bantu;
        bantu = bantu->next;
        delete hapus;
        //jadi kalo bantunya udah pindah di node setelahnya, hapusnya itu masih di node yang tetap , atau node sebelum bantu next, jadi yang dihapus itu node sebelum bantu next. 
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
    //kayaknya sih dihapus semua soalnya bantu = head = hapus, jadi kalo hapusnya di delete ya maka sama aja semua nilainya di delete karena kan pointernya sama?
}//AKU KURANG PAHAM INI!!!!!!!!!!!!!

// Tampilkan semua data Node di list
void tampil()
{
    if (!isEmpty())
    {
        Node *bantu = head;
        while (bantu != NULL)
        {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl; 
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}