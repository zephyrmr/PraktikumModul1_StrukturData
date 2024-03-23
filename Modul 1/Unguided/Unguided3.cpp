//Buat program menggunakan fungsi map.

#include <iostream>
#include <map>
#include <string>

using namespace std;
int main () {
    map < int, string > welcome = {
        {1,"Selamat Menjalani"},
        {2,"Ibadah Puasa"},
        {3,"Hari Pertama"},
    };  
    for (auto itr = welcome.begin();itr != welcome.end(); ++itr){
        cout << itr ->first << "." <<itr ->second <<endl ; 
    }   return 0;
}

