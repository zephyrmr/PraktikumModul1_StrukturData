// Tipe Data Primitif

#include <iostream>
using namespace std;

int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +,switch (op)
    cout << "Masukkan operator (+, -, *, /):";
    cin >> op;
    // If user enter to enter the operands
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2; 
    // Switch statement begins
    switch (op)
    {
    case '+':
        cout << "Hasil penjumlahan: " << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << "Hasil pengurangan: " << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << "Hasil perkalian: " << num1 * num2;
        break;
    // If user enter /
    case '/':
        if (num2 != 0)
        cout << "Hasil pembagian: " << num1 / num2;
    else
        cout << "Eroowr!Tidak dapat melakukan pembagian dengan nol.";
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
