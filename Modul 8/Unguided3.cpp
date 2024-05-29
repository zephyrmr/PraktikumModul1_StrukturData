// Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4.
// Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

#include <iostream>

using namespace std;
int hitungAngka(const int array[], int size, int target)
{
    int jumlah = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            jumlah++;
        }
    }
    return jumlah;
}

int main()
{
    const int size = 10;
    int array[size] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4;
    int jumlah = hitungAngka(array, size, target);
    cout << "---------------------------------------" << endl;
    cout << "        Menghitung Jumlah Angka        " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Data: ";
    for (int element : array)
    {
        cout << element << " ";
    }
    cout << "\nAngka yang dicari: " << target << endl;
    cout << "Ditemukan angka " << target << " dalam data sebanyak: " << jumlah << endl;
    return 0;
}