//DOUBLE LINKED LIST

#include <iostream>
using namespace std;

//deklarasi
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
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
    }//jadi sekarang hanya ada satu node/ tercipta 1 node karena headnya dipindah ke newNode sedangkan tail juga berada di newNode. 

    void pop()
    {//https://youtu.be/HoubOPoC44s?si=_nFEdwb5D-oVWQhX
        if (head == nullptr)
        {
            return;// Jika daftarnya kosong, tidak ada yang perlu dipop, jadi kembalikan.
        }
        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }   //jadi head sekarang jadi node pertama, soalnya prev nya NULL. 
        else
        {
            tail = nullptr;
        }

        delete temp;
    }

    bool update(int oldData, int newData)
    {
        Node *current = head;// current dan head emnunjuk ke simpul pertama. 

        while (current != nullptr)
        {
            if (current->data == oldData) // Nanti kan user disuruh untuk menginputkan old data, baru dibandingkan, kalo data cur nya sam adengan old data maka diganti ke new data, lalu cur pindah ke cur next. 
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll()//GAK BISA MENGILLUSTRASIKAN INI!!!!!!!!!!!
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

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }//ini diakhiri dengan current= current next, kalo current next nya menunjuk ke NULL ya berarti sudah tidak memenuhi syarat perulangan. 
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    while (true)//jika diberi while maka setelah memilih 1 case program akan menggulang dan membiarkan user memilih case lainnya tanpa me run ulang program dan keluar dari program.
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;//ketika pengguna memilih opsi "Exit" (case 6), program akan kembali dari fungsi main() dengan pernyataan return 0;, yang menyebabkan program berakhir.
}