#include <iostream>
using namespace std;

int main(){
    int data,i;
    cout<< "Masukkan jumlah data yang ingin diinputkan = ";
    cin >> data;
    int array[data];
    cout<< "Inputkan "<<data<< " data di bawah!"<<endl;
    
    for (i=0; i<data; i++){
        cout<< "Data ke-"<< i+1<< " = ";
        cin >> array[i];   
    }
    cout<< "Data array = ";
    for(i=0; i<data; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    //sunting agar dapat menampilkan nomor genap dan nomor ganjil
    cout<< "Nomor genap: ";
    for(i=0; i<data; i++){
        if (i%2 == 0){
            cout<<array[i]<<", ";
        }
    }
    cout<<endl;
    cout<< "Nomor ganjil: ";
    for(i=0; i<data; i++){
        if (i%2 != 0){
            cout<<array[i]<<", ";
        }
    }
    
    return 0;
}