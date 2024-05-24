// 1. Ubahlah penerapan queue pada guided dari array menjadi linked list, buatlah konsep antri dengan atribut Nama mahasiswa dan NIM

#include <iostream>

using namespace std;
struct Node
{
    string namaMhs;
    string nimMhs;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }
    bool isEmpty() { return front == nullptr; }
    void enqueue(string namaMhs, string nimMhs)
    {
        Node *newNode = new Node();
        newNode->namaMhs = namaMhs;
        newNode->nimMhs = nimMhs;
        newNode->next = nullptr;
        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrean kosong" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int countQueue()
    {
        int count = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void deleteQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
    void printQueue()
    {
        cout << "Data antrian Mahasiswa: " << endl;
        Node *temp = front;
        int pos = 1;
        while (temp != nullptr)
        {
            cout << pos << ". Nama: " << temp->namaMhs << "|| NIM: " << temp->nimMhs << endl;
            temp = temp->next;
            pos++;
        }
    }
};

int main()
{
    Queue queue;
    int pilihan;
    do
    {
        cout << "---------------------------------------------" << endl;
        cout << "   Data Antre Hats Coffee Khusus Mahasiswa   " << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1. Tambah antrean" << endl;
        cout << "2. Hapus antrean (selesai)" << endl;
        cout << "3. Hapus antrean (semua)" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------------------------\n"<< endl;
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
        {
            string namaMhs, nimMhs;
            cout << "Nama Mahasiswa : ";
            cin.ignore();
            getline(cin, namaMhs);
            cout << "NIM Mahasiswa : ";
            cin >> nimMhs;
            queue.enqueue(namaMhs, nimMhs);
            cout << "Anda telah ditambahkan dalam antrean 'Hats Coffee'"  << endl<<endl;
            queue.printQueue();
            break;
        }
        case 2:
        {
            if (queue.isEmpty())
            {
                cout << "Antrean kosong" << endl;
            }
            else
            {
                queue.dequeue();
                cout << "Satu antrean dihapus" << endl<<endl;
            }
            queue.printQueue();
            break;
        }
        case 3:
        {
            if (queue.isEmpty())
            {

                cout << "Antrean kosong" << endl;
            }
            else
            {
                queue.deleteQueue();
                cout << "Data seluruh antrean telah dihapus" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Terima kasih telah membeli 'Hats Coffee' " << endl;
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
        cout << endl;
    } while (pilihan != 4);
    return 0;
}