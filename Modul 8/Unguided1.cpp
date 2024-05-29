// Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
#include <iostream>

using namespace std;
void selectionSort(string &huruf, int n)
{
    int a, b, min;
    for (a = 0; a < n - 1; a++)
    {
        min = a;
        for (b = a + 1; b < n; b++)
            if (huruf[b] < huruf[min])
                min = b;
        char temp = huruf[a];
        huruf[a] = huruf[min];
        huruf[min] = temp;
    }
}
int binarySearch(string huruf, int kiri, int kanan, char target)
{
    while (kiri <= kanan)
    {
        int mid = kiri + (kanan - kiri) / 2;
        if (huruf[mid] == target)
            return mid;
        if (huruf[mid] < target)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    return -1;
}
int main()
{
    string kalimat;
    char input;
    cout << "---------------------------------------" << endl;
    cout << "      Pencarian Huruf pada Kalimat     " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> input;
    cout << endl;
    selectionSort(kalimat, kalimat.size());
    int result = binarySearch(kalimat, 0, kalimat.size() - 1, input);
    if (result == -1)
    {
        cout << "Huruf yang Anda cari tidak ditemukan!" << endl;
    }
    else
    {
        cout << "Huruf setelah diurutkan: " << kalimat << endl;
        cout << "Huruf ditemukan pada indeks ke- " << result << endl;
    }
    return 0;
}