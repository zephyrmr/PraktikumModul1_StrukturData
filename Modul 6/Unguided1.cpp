//Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan
//dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari
//depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string a;
    cout << "Masukkan Kalimat: ";
    cin >> a;

    stack<char> stackChar;
    int lengthInput = a.length();

    for (int i = 0; i < lengthInput; ++i)
    {
        stackChar.push(a[i]);
    }

    bool palindrom = true;
    for (int i = 0; i < lengthInput; ++i)
    {
        if (a[i] != stackChar.top())
        {
            palindrom = false;
            break;
        }
        stackChar.pop();
    }
    
    cout << "Kalimat tersebut adalah: ";
    if (palindrom)
    {
        cout << "Palindrom" << endl;
    }
    else
    {
        cout << "Bukan Palindrom" << endl;
    }

    return 0;
}