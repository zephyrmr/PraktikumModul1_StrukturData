// Kalo ada array [2] [2] [3] artinya ada, 2 kolom baris yang terdiri dari 2 baris dan 3 kolom
// Input dimasukkan oleh user

#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    //input jumlah array
    int a, b, c;
    cout<< "Input jumlah matriks: ";
    cin >> a;
    cout<< "Input ukuran matriks (baris dan kolom): ";
    cin >> b >> c;
    int arr[a][b][c];
    // Input elemen
    for (int i = 0; i < a; i++)
    {
        for (int o = 0; o < b; o++)
        {
            for (int p = 0; p < c; p++)
            {
                cout << "Input Array[" << i << "][" << o << "][" << p << "] = ";
                cin >> arr[i][o][p];
            }
        }
        cout << endl;
    }
    cout<< "==============================="<<endl;
    // Output Array
    for (int i = 0; i < a; i++)
    {
        for (int o = 0; o < b; o++)
        {
            for (int p = 0; p < c; p++)
            {
                cout << "Data Array[" << i << "][" << o << "][" << p << "] = " << arr[i][o][p] << endl;
            }
        }
    }
    cout << endl<<"======================="<<endl;
    // Tampilan array
    for (int i = 0; i < a; i++)
    {
        for (int o = 0; o < b; o++)
        {
            for (int p = 0; p < c; p++)
            {
                cout << arr[i][o][p] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}