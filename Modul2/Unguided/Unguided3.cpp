#include <iostream>
using namespace std;

int main()
{
    int a, i, pilih;
    cout << "Masukkan jumlah element array: ";
    cin >> a;
    int array[a];
    // input data
    cout << "Masukkan data array:" << endl;
    for (i = 0; i < a; i++)
    {
        cout << "Data indeks ke-" << (i + 1) << " = ";
        cin >> array[i];
    }
    // print data
    cout << "Data array: ";
    for (i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Pilihan Menu:" << endl;
    cout << "1. Nilai maksimum" << endl;
    cout << "2. Nilai minimum" << endl;
    cout << "3. Nilai rata- rata" << endl;
    cout << "Pilihan Anda:";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
    {
        int maks = array[0];
        for (i = 0; i < a; i++)
        {
            if (maks < array[i])
            {
                maks = array[i];     
            }
        }cout << "Nilai maksimum: "<< maks;  
        break;
    }

    case 2:
    {  
        int min = array[0];
        for (i = 0; i < a; i++)
        {
            if (min > array[i])
            {
                min = array[i];
            }
        }cout <<"Nilai minimum: "<< min;
        break;
    }
    case 3:
    {
        int sum;
        for (int i = 0; i < a; i++)
        {
            sum += array[i];
        }
        float ratarata = sum / a;
        cout << "Nilai rata-rata: " << ratarata << endl;
        break;
    }
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

    return 0;
}
