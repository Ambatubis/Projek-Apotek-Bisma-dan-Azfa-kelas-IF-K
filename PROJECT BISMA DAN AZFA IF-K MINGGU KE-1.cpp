#include <iostream>
using namespace std;

int main(){
    cout << "=== SELAMAT DATANG DI AMBATEK ===\n";
    cout << "MOHON DIISI DENGAN BAIK DAN BENAR\n\n";
    struct apotek
{
    string nama;
    int umur;
    string obat;
    int total;
}pembeli[2][4];

    for(int i = 0; i< 2; i++){
        for(int j = 0; j < 1; j++){
            cout << "Masukkan Nama Anda \t: ";
            cin >> pembeli[i][j].nama;
            cout << "Masukan Umur Anda \t: ";
            cin >> pembeli[i][j].umur; 
            cout << "Obat yang di butuhkan \t: ";
            cin >> pembeli[i][j].obat;
            cout << "Berapa banyak \t\t: ";
            cin >> pembeli[i][j].total;
            cout << "\n";
        }
    }

    for(int i = 0; i< 2; i++){
        cout << "[" << i+1 << "]\n";
        for(int j = 0; j < 1; j++){
            cout << "Nama anda :" << pembeli[i][j].nama << endl;
            cout << "Umur      :" << pembeli[i][j].umur << endl;
            cout << "Obat      :" << pembeli[i][j].obat << endl;
            cout << "Total Obat:" << pembeli[i][j].total << endl;
        }
    cout << endl;
    }
    
}