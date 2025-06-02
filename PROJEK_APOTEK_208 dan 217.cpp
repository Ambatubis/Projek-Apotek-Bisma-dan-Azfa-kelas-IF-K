#include <iostream>
#include <fstream> // untuk file I/O
using namespace std;

void Menu_Utama();
void Menu_Satu();
void Menu_Dua();
void Menu_Tiga();
void Menu_Empat();
void Menu_Strip();
void Menu_Tablet();
void Menu_Input_Strip();
void Menu_Input_Tablet();
void nota();
void Menu_Sequential_Search_Non_Sentinel();
void Menu_Sequential_Search_Sentinel();
void Binary();
void Menu_ASC_dan_DCS();
void Bubble_Sort_Ascending();
void Bubble_Sort_Descending();
void Selection_Sort_Ascending();
void Selection_Sort_Descending();
void Insertion_Sort_Ascending();
void Insertion_Sort_Descending();
void Shell_Sort_Ascending();
void Shell_Sort_Descending();
void quickSort_Ascending(int low, int high);
void quickSort_Descending(int low, int high);
void Quick_Sort_Ascending();
void Quick_Sort_Descending();
void merge_Ascending(int left, int mid, int right);
void merge_Descending(int left, int mid, int right);
void mergeSort_Ascending(int left, int right);
void mergeSort_Descending(int left, int right);
void Merge_Sort_Ascending();
void Merge_Sort_Descending();
void Menu_Salah();
void Kembali();
void keluar();
void Simpan_Pesanan(); // fungsi untuk menyimpan data pesanan
void Baca_Pesanan_Dari_File();

struct obat_strip
{
    int no_obat[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    string nama_obat[15] = {"PARACETAMOL 500 MG (1 STRIP)", "VITACIMIN (1 STRIP)", "ANTIMO (1 STRIP)", "BETADINE 5 ML", "OBH 100 ML", 
                            "AMBROXOL 30 MG (1 STRIP)", "ALPARA (1 STRIP)", "TOLAK ANGIN (1 PACK)", "RHINOS SR (1 STRIP)", "PARATUSIN (1 STRIP)",
                            "PROMAG (1 STRIP)", "BODREX (1 STRIP)", "PANADOL (1 STRIP)", "DIAPET (1 STRIP)", "IBUPROFEN TRIMAN 400 MG (1 PACK)"};
    int harga_obat[15] = {6000, 8000, 5000, 7000, 20000, 
                          20000, 8000, 20000, 10000, 20000, 
                          8000, 6000, 12000, 7000, 25000,};
};

struct obat_tablet
{
    int no_obat[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string nama_obat[13] = {"PARACETAMOL 500 MG (1 TABLET)", "VITACIMIN (1 TABLET)", "ANTIMO (1 TABLET)", "AMBROXOL 30 MG (1 TABLET)", 
                            "ALPARA (1 TABLET)", "TOLAK ANGIN (1 BUAH)", "RHINOS SR (1 TABLET)", "PARATUSIN (1 TABLET)", "PROMAG (1 TABLET)", 
                            "BODREX (1 TABLET)", "PANADOL (1 TABLET)", "DIAPET (1 TABLET)", "IBUPROFEN TRIMAN 400 MG (1 TABLET)"};
    int harga_obat[13] = {1000, 1000, 500, 3000, 1000, 
                          5000, 2000, 3000, 1000, 1000, 
                          3000, 1000, 4000};
};

struct ItemPesanan
{
    int no_obat;
    string nama_obat;
    int harga_obat;
};

struct Pemesanan
{
    string nama, pilihan;
    ItemPesanan obat_dipesan[10];
} pesanan;

Pemesanan pembeli[10];  // Array untuk menyimpan data member yang telah diinput
int jumlah_pembeli = 0; // Jumlah member yang sudah tersimpan

char pilih, yesno;
int menupil, pilihan, banyak, obat_pesanan = 0, total_harga = 0;

int partition_Ascending(int low, int high)
{
    string pivot = pembeli[high].nama;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (pembeli[j].nama <= pivot)
        {
            i++;
            swap(pembeli[i], pembeli[j]);
        }
    }

    swap(pembeli[i + 1], pembeli[high]);
    return i + 1;
}

int partition_Descending(int low, int high)
{
    string pivot = pembeli[high].nama;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (pembeli[j].nama >= pivot)
        {
            i++;
            swap(pembeli[i], pembeli[j]);
        }
    }

    swap(pembeli[i + 1], pembeli[high]);
    return i + 1;
}

int main()
{
    Menu_Utama();
    switch (pilihan)
    {
    case 1:
        Menu_Satu();
        switch (pilihan)
        {
        case 1:
            Menu_Strip();
            Menu_Input_Strip();
            nota();
            Kembali();
            break;
        case 2:
            Menu_Tablet();
            Menu_Input_Tablet();
            nota();
            Kembali();
            break;
        }
        return 0;
    case 2:
        Menu_Dua();
        Kembali();
    case 3:
        Menu_Tiga();
        switch (pilihan)
        {
        case 1:
            Menu_Sequential_Search_Non_Sentinel();
            Kembali();
            break;
        case 2:
            Menu_Sequential_Search_Sentinel();
            Kembali();
            break;
        case 3:
            Binary();
            Kembali();
            break;
        default:
            Menu_Salah();
            Kembali();
            break;
        }
        return 0;
    case 4:
        Menu_Empat();
        switch (pilihan)
        {
        case 1:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Bubble_Sort_Ascending();
                Kembali();
                break;
            case 2:
                Bubble_Sort_Descending();
                Kembali();
                break;
            }
            return 0;
        case 2:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Selection_Sort_Ascending();
                Kembali();
                break;
            case 2:
                Selection_Sort_Descending();
                Kembali();
                break;
            }
            return 0;
        case 3:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Insertion_Sort_Ascending();
                Kembali();
                break;
            case 2:
                Insertion_Sort_Descending();
                Kembali();
                break;
            }
            return 0;
        case 4:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Shell_Sort_Ascending();
                Kembali();
                break;
            case 2:
                Shell_Sort_Descending();
                Kembali();
                break;
            }
            return 0;
        case 5:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Quick_Sort_Ascending();
                Kembali();
                break;
            case 2:
                Quick_Sort_Descending();
                Kembali();
                break;
            }
            break;
        case 6:
            Menu_ASC_dan_DCS();
            switch (pilihan)
            {
            case 1:
                Merge_Sort_Ascending();
                Kembali();
            case 2:
                Merge_Sort_Descending();
                Kembali();
            }
            break;
        default:
            Menu_Salah();
            Kembali();
            break;
        }
        return 0;
    case 5:
        Simpan_Pesanan();
        Kembali();
        break;
    default:
        Menu_Salah();
        Kembali();
        break;
    }
    return 0;
}

void Menu_Utama()
{
    cout << "# SELAMAT DATANG DI AMBATEK #" << endl;
    cout << "=== MAIN MENU ===\n\n";
    cout << "1. INPUT PEMBELI\n";
    cout << "2. MELIHAT PEMBELI\n";
    cout << "3. MENCARI PEMBELI\n";
    cout << "4. SORTING\n";
    cout << "5. SIMPAN DAN EXIT\n";
    cout << "Pilih Opsi : "; 
    cin >> pilihan;
    system("cls");
}

void Menu_Satu()
{
    cout << "=== MENU OBAT===\n\n";
    cout << "1. OBAT/STRIP\n";
    cout << "2. OBAT/TABLET\n";
    cout << "Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();
    cin.fail();
    cin.clear();
}

void Menu_Strip()
{
    system("cls");
    cout << "\t\t  Menu\t\t\t" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| \t\tNama Menu\t\t|     Harga\t|" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1. PARACETAMOL 500 MG (1 STRIP)\t| Rp. 6.000\t|" << endl;
    cout << "| 2. VITACIMIN (1 STRIP)\t\t| Rp. 8.000\t|" << endl;
    cout << "| 3. ANTIMO (1 STRIP)\t\t\t| Rp. 5.000\t|" << endl;
    cout << "| 4. BETADINE 5 ML\t\t\t| Rp. 7.000\t|" << endl;
    cout << "| 5. OBH COMBI 100 ML\t\t\t| Rp. 20.000\t|" << endl;
    cout << "| 6. AMBROXOL 30 MG (1 STRIP)\t\t| Rp. 20.000\t|" << endl;
    cout << "| 7. ALPARA (1 STRIP)\t\t\t| Rp. 8.000\t|" << endl;
    cout << "| 8. TOLAK ANGIN (1 PACK)\t\t| Rp. 20.000\t|" << endl;
    cout << "| 9. RHINOS SR (1 STRIP)\t\t| Rp. 10.000\t|" << endl;
    cout << "| 10. PARATUSIN (1 STRIP)\t\t| Rp. 20.000\t|" << endl;
    cout << "| 11. PROMAG (1 STRIP)\t\t\t| Rp. 8.000\t|" << endl;
    cout << "| 12. BODREX (1 STRIP)\t\t\t| Rp. 6.000\t|" << endl;
    cout << "| 13. PANADOL (1 STRIP)\t\t\t| Rp. 12.000\t|" << endl;
    cout << "| 14. DIAPET (1 STRIP)\t\t\t| Rp. 7.000\t|" << endl;
    cout << "| 15. IBUPROFEN TRIMAN 400 MG (1 PACK)\t| Rp. 25.000\t|" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void Menu_Tablet()
{
    system("cls");
    cout << "\t\t  Menu\t\t\t" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| \t\tNama Menu\t\t|     Harga\t|" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1. PARACETAMOL 500 MG (1 TABLET)\t| Rp. 1.000\t|" << endl;
    cout << "| 2. VITACIMIN (1 TABLET)\t\t| Rp. 1.000\t|" << endl;
    cout << "| 3. ANTIMO (1 TABLET)\t\t\t| Rp. 500\t|" << endl;
    cout << "| 4. AMBROXOL 30 MG (1 TABLET)\t\t| Rp. 3.000\t|" << endl;
    cout << "| 5. ALPARA (1 TABLET)\t\t\t| Rp. 1.000\t|" << endl;
    cout << "| 6. TOLAK ANGIN (1 BUAH)\t\t| Rp. 5.000\t|" << endl;
    cout << "| 7. RHINOS SR (1 TABLET)\t\t| Rp. 2.000\t|" << endl;
    cout << "| 8. PARATUSIN (1 TABLET)\t\t| Rp. 3.000\t|" << endl;
    cout << "| 9. PROMAG (1 TABLET)\t\t\t| Rp. 1.000\t|" << endl;
    cout << "| 10. BODREX (1 TABLET)\t\t\t| Rp. 1.000\t|" << endl;
    cout << "| 11. PANADOL (1 TABLET)\t\t| Rp. 3.000\t|" << endl;
    cout << "| 12. DIAPET (1 TABLET)\t\t\t| Rp. 1.000\t|" << endl;
    cout << "| 13. IBUPROFEN TRIMAN 400 MG (1 TABLET)| Rp. 4.000\t|" << endl;
    cout << "---------------------------------------------------------" << endl;
}

void Menu_Input_Strip()
{
    obat_strip list_menu_obat;
    cout << "Masukkan Nama Pembeli : ";
    cin >> pesanan.nama;
    
    pesanan.pilihan = "OBAT/STRIP";
    
    char lanjut;
        // Error handling untuk input nomor OBAT yang benar
        do
        {
            cout << "Masukkan Nomor Obat yang dipilih (1-15): "; 
            cin >> menupil;
            cout << "Ingin berapa banyak jumlah obat : "; 
            cin >> banyak;
            if (menupil > 15 || menupil < 1)
                cout << "Pilih menu dengan benar" << endl;
        } while (menupil < 1);
        
        for (int i = 0; i < 15; i++)
        {
            if (list_menu_obat.no_obat[i] == menupil)
            {
                pesanan.obat_dipesan[obat_pesanan].no_obat = list_menu_obat.no_obat[i];
                pesanan.obat_dipesan[obat_pesanan].nama_obat = list_menu_obat.nama_obat[i];
                pesanan.obat_dipesan[obat_pesanan].harga_obat = list_menu_obat.harga_obat[i];
            }
        }
        obat_pesanan++;
        if (jumlah_pembeli < 15) 
        {
            pembeli[jumlah_pembeli] = pesanan;
            jumlah_pembeli++;
        }
}

void Menu_Input_Tablet()
{
    obat_tablet list_menu_obat;
    cout << "Masukkan Nama Pembeli : ";
    cin >> pesanan.nama;
    
    pesanan.pilihan = "OBAT/TABLET";
    
    char lanjut;
        // Error handling untuk input nomor OBAT yang benar
        do
        {
            cout << "Masukkan Nomor Obat yang dipilih (1-13): "; 
            cin >> menupil;
            cout << "Ingin berapa banyak jumlah obat : "; 
            cin >> banyak;
            if (menupil > 13 || menupil < 1)
                cout << "Pilih menu dengan benar" << endl;
        } while (menupil < 1);
        
        for (int i = 0; i < 13; i++)
        {
            if (list_menu_obat.no_obat[i] == menupil)
            {
                pesanan.obat_dipesan[obat_pesanan].no_obat = list_menu_obat.no_obat[i];
                pesanan.obat_dipesan[obat_pesanan].nama_obat = list_menu_obat.nama_obat[i];
                pesanan.obat_dipesan[obat_pesanan].harga_obat = list_menu_obat.harga_obat[i];
            }
        }
        obat_pesanan++;
        if (jumlah_pembeli < 13) 
        {
            pembeli[jumlah_pembeli] = pesanan;
            jumlah_pembeli++;
        }
}

void nota()
{
    Pemesanan *ptrPesanan = &pesanan;

    cout << "----------  Nota  ----------" << endl;
    cout << "Nama\t\t: " << ptrPesanan->nama << endl;

    for (int j = 0; j < obat_pesanan; j++)
    {
        ItemPesanan *ptrItem = &ptrPesanan->obat_dipesan[j];
        cout << "Pesanan " << j + 1 << "\t: " << ptrItem->nama_obat << endl;
        cout << "Harga\t\t: Rp " << ptrItem->harga_obat << endl;
        cout << "Total Obat\t: " << banyak << endl;
        total_harga += banyak * ptrItem->harga_obat;
    }

    cout << "----------------------------" << endl;
    cout << "Total\t\t: Rp " << total_harga << endl;
    cout << "--------Terima Kasih--------" << endl;

    // Reset setelah nota tampil
    obat_pesanan = 0;
    total_harga = 0;
}

void Menu_Dua()
{
    system("cls");
    cout << "========== DATA PESANAN ==========\n";
    if (jumlah_pembeli == 0)
    {
        cout << "Belum ada pembeli yang membeli.\n";
    }
    else
    {
        for (int i = 0; i < jumlah_pembeli; i++)
        {
            cout << "Pembeli ke-" << i + 1 << endl;
            cout << "Nama\t: " << pembeli[i].nama << endl; 
            cout << "Obat\t: " << pembeli[i].obat_dipesan[0].nama_obat << endl;
            cout << "-------------------------------\n";
        }
    }
    // Tambahan: baca ulang dari file
    cout << "\n>>> Data disimpan di file:\n";
    Baca_Pesanan_Dari_File();
}

void Menu_Tiga()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU SEARCHING ===\n\n";
    cout << "1. SEQUENTIAL SEARCH NON SENTINEL\n";
    cout << "2. SEQUENTIAL SEARCH SENTINEL\n";;
    cout << "3. BINARY\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Menu_Sequential_Search_Non_Sentinel()
{
    string cari;
    cout << "Masukkan nama pembeli yang ingin dicari: ";
    cin >> cari;
    
    bool ditemukan = false;
    for (int i = 0; i < jumlah_pembeli; i++)
    {
        if (pembeli[i].nama == cari)
        {
            cout << "Data ditemukan!";
            cout << "\nNama\t: " << pembeli[i].nama;
            cout << "\nObat\t: " << pembeli[i].obat_dipesan[0].nama_obat;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Data tidak ditemukan.\n";
    }
}

void Menu_Sequential_Search_Sentinel()
{
    string cari;
    cout << "Masukkan nama pembeli yang ingin dicari: ";
    cin >> cari;
    
    pembeli[jumlah_pembeli].nama = cari; // Menambahkan sentinel
    
    int i = 0;
    while (pembeli[i].nama != cari)
    {
        i++;
    }
    
    if (i < jumlah_pembeli)
    {
        cout << "Data ditemukan!";
        cout << "\nNama\t: " << pembeli[i].nama;
        cout << "\nObat\t: " << pembeli[i].obat_dipesan[0].nama_obat;
    }
    else
    {
        cout << "Data tidak ditemukan.\n";
    }
}

void Binary()
{
    if (jumlah_pembeli == 0)
    {
        cout << "Belum ada data yang tersimpan.\n";
        return;
    }
    
    // Bubble Sort untuk mengurutkan data berdasarkan nama sebelum Binary Search
    for (int i = 0; i < jumlah_pembeli - 1; i++)
    {
        for (int j = 0; j < jumlah_pembeli - i - 1; j++)
        {
            if (pembeli[j].nama > pembeli[j + 1].nama)
            {
                swap(pembeli[j], pembeli[j + 1]);
            }
        }
    }
    
    string cari;
    cout << "Masukkan nama pembeli yang ingin dicari: ";
    cin >> cari;
    
    int kiri = 0, kanan = jumlah_pembeli - 1, tengah;
    bool ditemukan = false;
    
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        
        if (pembeli[tengah].nama == cari)
        {
            cout << "Data ditemukan!";
            cout << "\nNama\t: " << pembeli[tengah].nama;
            cout << "\nObat\t: " << pembeli[tengah].obat_dipesan[0].nama_obat;
            ditemukan = true;
            break;
        }
        else if (pembeli[tengah].nama < cari)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }
    
    if (!ditemukan)
    {
        cout << "Data tidak ditemukan.\n";
    }
}

void Menu_Empat()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU SORTING ===\n\n";
    cout << "1. BUBBLE SORT\n";
    cout << "2. SELECTION SORT\n";
    cout << "3. INSERTION SORT\n";
    cout << "4. SHELL SORT\n";
    cout << "5. QUICK SORT\n";;
    cout << "6. MERGE SORT\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Menu_ASC_dan_DCS()
{
    int *ptrPilihan = &pilihan; // pointer ke variabel pilihan

    cout << "=== MENU ASCENDING DAN DESCENDING ===\n";
    cout << "PENCARIAN BERDASARKAN NAMA\n\n";
    cout << "1. ASCENDING\n";
    cout << "2. DISCENDING\n";
    cout << "Pilih Opsi : "; 
    cin >> *ptrPilihan; // input nilai ke alamat yang ditunjuk pointer
    cin.ignore();
    system("cls");
}

void Bubble_Sort_Ascending()
{
    for (int i = 0; i < jumlah_pembeli - 1; i++)
    {
        for (int j = 0; j < jumlah_pembeli - i - 1; j++)
        {
            if (pembeli[j].nama > pembeli[j + 1].nama)
            {
                swap(pembeli[j], pembeli[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan menggunakan Bubble Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Bubble_Sort_Descending()
{
    for (int i = 0; i < jumlah_pembeli - 1; i++)
    {
        for (int j = 0; j < jumlah_pembeli - i - 1; j++)
        {
            if (pembeli[j].nama < pembeli[j + 1].nama)
            {
                swap(pembeli[j], pembeli[j + 1]);
            }
        }
    }
    cout << "Data telah diurutkan menggunakan Bubble Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Selection_Sort_Ascending()
{
    for (int i = 0; i < jumlah_pembeli - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < jumlah_pembeli; j++)
        {
            if (pembeli[j].nama < pembeli[min_index].nama)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(pembeli[i], pembeli[min_index]);
        }
    }

    cout << "Data telah diurutkan menggunakan Selection Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Selection_Sort_Descending()
{
    for (int i = 0; i < jumlah_pembeli - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < jumlah_pembeli; j++)
        {
            if (pembeli[j].nama > pembeli[min_index].nama)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(pembeli[i], pembeli[min_index]);
        }
    }

    cout << "Data telah diurutkan menggunakan Selection Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Insertion_Sort_Ascending()
{
    for (int i = 1; i < jumlah_pembeli; i++)
    {
        Pemesanan key = pembeli[i];
        int j = i - 1;

        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && pembeli[j].nama > key.nama)
        {
            pembeli[j + 1] = pembeli[j];
            j--;
        }

        // Tempatkan elemen pada posisi yang tepat
        pembeli[j + 1] = key;
    }

    cout << "Data telah diurutkan menggunakan Insertion Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Insertion_Sort_Descending()
{
    for (int i = 1; i < jumlah_pembeli; i++)
    {
        Pemesanan key = pembeli[i];
        int j = i - 1;

        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && pembeli[j].nama < key.nama)
        {
            pembeli[j + 1] = pembeli[j];
            j--;
        }

        // Tempatkan elemen pada posisi yang tepat
        pembeli[j + 1] = key;
    }

    cout << "Data telah diurutkan menggunakan Insertion Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Shell_Sort_Ascending()
{
    for (int gap = jumlah_pembeli / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < jumlah_pembeli; i++)
        {
            Pemesanan temp = pembeli[i];
            int j;
            for (j = i; j >= gap && pembeli[j - gap].nama > temp.nama; j -= gap)
            {
                pembeli[j] = pembeli[j - gap];
            }
            pembeli[j] = temp;
        }
    }

    cout << "Data telah diurutkan menggunakan Shell Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void Shell_Sort_Descending()
{
    for (int gap = jumlah_pembeli / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < jumlah_pembeli; i++)
        {
            Pemesanan temp = pembeli[i];
            int j;
            for (j = i; j >= gap && pembeli[j - gap].nama < temp.nama; j -= gap)
            {
                pembeli[j] = pembeli[j - gap];
            }
            pembeli[j] = temp;
        }
    }

    cout << "Data telah diurutkan menggunakan Shell Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

// Fungsi untuk menukar dua elemen
void quickSort_Ascending(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition_Ascending(low, high);
        quickSort_Ascending(low, pivotIndex - 1);
        quickSort_Ascending(pivotIndex + 1, high);
    }
}

void Quick_Sort_Ascending()
{
    quickSort_Ascending(0, jumlah_pembeli - 1);
    cout << "Data telah diurutkan menggunakan Quick Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

// Fungsi untuk menukar dua elemen
void quickSort_Descending(int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition_Descending(low, high);
        quickSort_Descending(low, pivotIndex - 1);
        quickSort_Descending(pivotIndex + 1, high);
    }
}

void Quick_Sort_Descending()
{
    quickSort_Descending(0, jumlah_pembeli - 1);
    cout << "Data telah diurutkan menggunakan Quick Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void merge_Ascending(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    Pemesanan* L = new Pemesanan[n1];
    Pemesanan* R = new Pemesanan[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = pembeli[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = pembeli[mid + 1 + j];

    int i = 0, j = 0, k = left;
    // Merge kembali ke array utama dengan urutan berdasarkan nama
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) 
        {
            pembeli[k] = L[i];
            i++;
        } else 
        {
            pembeli[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L jika ada
    while (i < n1) 
    {
        pembeli[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen R jika ada
    while (j < n2) 
    {
        pembeli[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_Ascending(int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort_Ascending(left, mid);
        mergeSort_Ascending(mid + 1, right);

        merge_Ascending(left, mid, right);
    }
}

void Merge_Sort_Ascending()
{
    mergeSort_Ascending(0, jumlah_pembeli - 1);
    cout << "Data telah diurutkan menggunakan Merge Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void merge_Descending(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Buat array sementara
    Pemesanan* L = new Pemesanan[n1];
    Pemesanan* R = new Pemesanan[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++)
        L[i] = pembeli[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = pembeli[mid + 1 + j];

    int i = 0, j = 0, k = left;
    // Merge kembali ke array utama dengan urutan berdasarkan nama
    while (i < n1 && j < n2) {
        if (L[i].nama >= R[j].nama) 
        {
            pembeli[k] = L[i];
            i++;
        } else 
        {
            pembeli[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L jika ada
    while (i < n1) 
    {
        pembeli[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen R jika ada
    while (j < n2) 
    {
        pembeli[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort_Descending(int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort_Descending(left, mid);
        mergeSort_Descending(mid + 1, right);

        merge_Descending(left, mid, right);
    }
}

void Merge_Sort_Descending()
{
    mergeSort_Descending(0, jumlah_pembeli - 1);
    cout << "Data telah diurutkan menggunakan Merge Sort!\n";
    cout << "Silahkan cek di menu ke-2 (MELIHAT PEMBELI)\n";
}

void keluar()
{
    cout << "= Terima kasih, sampai jumpa nanti lagi! =";
}

void Kembali()
{
    cout << "\nKembali ke menu utama? (y/n) ";
    cin >> yesno;
    if (yesno == 'y' || yesno == 'Y')
    {
        system("CLS");
        main();
    }
    else if (yesno == 'n' || yesno == 'N')
    {
        keluar();
    }
    else
    {
        system("cls");
        keluar();
    }
}

void Menu_Salah(){
    system("cls");
    cout << "Tolong pilih angka 1, 2 dan 3 ";
}

void Simpan_Pesanan()
{
    ofstream file_out("data_pelanggan.txt", ios::app);
    if (file_out.is_open()) {
        for (int i = 0; i < jumlah_pembeli; i++) {
            file_out << "Nama: " << pembeli[i].nama << endl;
            file_out << "Jenis: " << pembeli[i].pilihan << endl;
            file_out << "Obat: " << pembeli[i].obat_dipesan[0].nama_obat << endl;
            file_out << "Harga: Rp " << pembeli[i].obat_dipesan[0].harga_obat << endl;
            file_out << "-----------------------------" << endl;
        }
        file_out.close();
        cout << "\nData berhasil disimpan ke file pesanan_data.txt\n";
    } else {
        cout << "Gagal menyimpan data ke file.\n";
    }
}

void Baca_Pesanan_Dari_File()
{
    ifstream file_in("data_pelanggan.txt");
    if (file_in.is_open()) {
        string baris;
        cout << "=== DATA DARI FILE pesanan_data.txt ===\n";
        while (getline(file_in, baris)) {
            cout << baris << endl;
        }
        file_in.close();
    }
}