// 1. Ubahlah penerapan queue pada guided dari array menjadi linked list
#include <iostream>

using namespace std;

const bool IS_LIMITLESS = true;
const int maksimalQueue = 5;
int length = 0;

struct QueueTeller
{
    string data;
    QueueTeller *next;
} *newData, *front, *back, *current;

bool isFull()
{
    return (IS_LIMITLESS == false && length == maksimalQueue);
}

bool isEmpty()
{
    return back == NULL;
}

void enqueueAntrian(string data)
{
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        newData = new QueueTeller();
        newData->data = data;
        newData->next = NULL;
        if (isEmpty())
        {
            front = back = newData;
            length++;
        }
        else
        {
            back->next = newData;
            back = newData;
            length++;
        }
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        current = front;
        front = front->next;
        newData = NULL;
        length--;
    }
}

int countQueue()
{
    return length;
}

void clearQueue()
{
    current = front;
    while (current != NULL)
    {
        newData = current;
        current = current->next;
        newData = NULL;
    }
    front = back = NULL;
    length = 0;
}

void viewQueue()
{
    int counter = 1;
    cout << "Data antrian teller : " << endl;
    current = front;
    while (current != NULL)
    {
        cout << counter++ << ". " << current->data << endl;
        current = current->next;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    enqueueAntrian("Anisah");
    enqueueAntrian("Syifa");
    viewQueue();
    cout << "Jumlah Peserta " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah Peserta " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah Peserta " << countQueue() << endl;
    return 0;
}