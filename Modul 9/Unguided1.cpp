#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()

{

    int Anisah_2311102080;

    cout << "Silakan masukkan jumlah simpul: ";

    cin >> Anisah_2311102080;

    vector<string> simpul(Anisah_2311102080);

    vector<vector<int>> busur(Anisah_2311102080, vector<int>(Anisah_2311102080, 0));

    cout << "Silakan masukkan nama simpul " << endl;

    for (int i = 0; i < Anisah_2311102080; i++)

    {

        cout << "Simpul ke-" << (i + 1) << ": ";

        cin >> simpul[i];
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < Anisah_2311102080; i++)

    {

        for (int j = 0; j < Anisah_2311102080; j++)

        {

            cout << simpul[i] << " --> " << simpul[j] << " = ";

            cin >> busur[i][j];
        }
    }

    cout << endl;

    cout << setw(7) << " ";

    for (int i = 0; i < Anisah_2311102080; i++)

    {
        cout << setw(8) << simpul[i];
    }

    cout << endl;

    for (int i = 0; i < Anisah_2311102080; i++)

    {

        cout << setw(7) << simpul[i];

        for (int j = 0; j < Anisah_2311102080; j++)

        {

            cout << setw(8) << busur[i][j];
        }

        cout << endl;
    }
}