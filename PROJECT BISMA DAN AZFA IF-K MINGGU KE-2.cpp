#include <iostream>
using namespace std;

const int max_obat = 10;
void inputobat(int total, int Obat);

struct apotek {
    string nama;
    int umur;
    string obat[max_obat]; 
    int total[max_obat];   
    int jumlahObat = 0;    
} pembeli[10];

int main() {
    int jmlh;
    cout << "=== SELAMAT DATANG DI AMBATEK ===\n";
    cout << "MOHON DIISI DENGAN BAIK DAN BENAR\n\n";
    cout << "Masukkan jumlah pembeli : ";
    cin >> jmlh;
    for (int i = 0; i < jmlh; i++) {
        cout << "Masukkan Nama Anda\t: ";
        cin >> pembeli[i].nama;
        cout << "Masukkan Umur Anda\t: ";
        cin >> pembeli[i].umur;
        inputobat(i, 0);
    }
    cout << "\n=== DATA PEMBELI OBAT ===\n";
    for (int i = 0; i < jmlh; i++) {
        cout << "\nPembeli [" << i + 1 << "]\n";
        cout << "Nama Anda  : " << pembeli[i].nama << endl;
        cout << "Umur       : " << pembeli[i].umur << " tahun" << endl;
        cout << "Daftar Obat:\n";
        for (int j = 0; j < pembeli[i].jumlahObat; j++) {
            cout << pembeli[i].obat[j] << " Jumlah : " << pembeli[i].total[j] << endl;
        }
    }
    return 0;
}

    void inputobat(int total, int Obat) {
        if (Obat >= max_obat) {
            cout << "Obat yang diinput sudah mencapai batas maksimal!\n";
            return;
        }
        else
        {
            cout << "Obat yang dibutuhkan\t: ";
            cin >> pembeli[total].obat[Obat];
            cout << "Berapa banyak\t\t: ";
            cin >> pembeli[total].total[Obat];
            pembeli[total].jumlahObat++;
            char ulang;
            do {
                cout << "Tambah obat lagi? (y/n): ";
                cin >> ulang;
            } while (ulang != 'y' && ulang != 'n');
        
            if (ulang == 'y' || ulang == 'Y') {
                inputobat(total, Obat + 1);
            }
        }
        
    
    }