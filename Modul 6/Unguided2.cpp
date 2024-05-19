#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string a;

    // Loop untuk memastikan a terdiri dari minimal 3 kata
    while (true) {
        cout << "Masukkan Kalimat (minimal 3 kata): ";
        getline(cin, a);

        // Hitung jumlah kata
        int wordCount = 0;
        bool inWord = false;
        for (char c : a) {
            if (isspace(c)) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }
        }
        if (inWord) wordCount++;

        if (wordCount >= 3) {
            break;
        } else {
            cout << "Kalimat harus terdiri dari minimal 3 kata. Silakan coba lagi." << endl;
        }
    }

    stack<char> stackChar;
    int lengthInput = a.length();

    for (int i = 0; i < lengthInput; ++i) {
        stackChar.push(a[i]);
    }

    cout << "Kalimat terbalik: ";
    for (int i = 0; i < lengthInput; ++i) {
        cout << stackChar.top();
        stackChar.pop();
    }
    cout << endl;

    return 0;
}
