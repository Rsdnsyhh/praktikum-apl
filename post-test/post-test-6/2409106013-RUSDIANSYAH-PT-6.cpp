#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_NASABAH 4

struct Nasabah {
    string nama;
    string nomorRekening;
    int saldo;
};

Nasabah dataNasabah[MAX_NASABAH];
int panjang = 0;
int Kesalahan = 0;

// Deklarasi fungsi sorting
void bubbleSortNama(Nasabah arr[], int n); // Sorting nama ascending (Bubble Sort)
void selectionSortSaldo(Nasabah arr[], int n); // Sorting saldo descending (Selection Sort)
void insertionSortNomorRekening(Nasabah arr[], int n); // Sorting nomor rekening ascending (Insertion Sort)

void buatRekening(Nasabah* data, int* size);
void hapusRekening(Nasabah* data, int* size);
void tampilkanRekening(Nasabah* data, int size, int sortMethod = 0);
void updateRekening(Nasabah* data, int size);
void cekSaldo(const Nasabah* data, int size);
void isiSaldo(Nasabah* data, int size);
void tarikSaldo(Nasabah* data, int size);
void menuAdmin(Nasabah* data, int* size, int* errors);
void menuUser(Nasabah* data, int size, int* errors);

int main() {
    while (true) {
        cout << "<====================================================================>" << endl;
        cout << "      |        SELAMAT DATANG DI PROGRAM BANK SEDERHANA         |       " << endl;
        cout << "<====================================================================>" << endl;
        cout << "      |                1. Login Sebagai Admin                  |       " << endl;
        cout << "      |                2. Login Sebagai User                   |       " << endl;
        cout << "      |                     0. Keluar                          |       " << endl;
        cout << "<====================================================================>" << endl;

        int pilihan;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string username,password;
            int kesalahanLogin = 0;

            while (kesalahanLogin < 3) {
                cout << "Masukkan Username: ";
                cin >> username;
                cout << "Masukkan Password: ";
                cin >> password;

                if (username == "admin" && password == "admin123") {
                    menuAdmin(dataNasabah, &panjang, &Kesalahan);
                    break;
                } else {
                    kesalahanLogin++;
                    cout << "Username atau password salah. Kesalahan ke-" << kesalahanLogin << endl;
                }
            }

            if (kesalahanLogin >= 3) {
                cout << "Anda melakukan 3 kali kesalahan login. Program dihentikan" << endl;
                return 0;
            }
        } else if (pilihan == 2) {
            string username, password;
            int kesalahanLogin = 0;

            while (kesalahanLogin < 3) {
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;

                if (username == "user" && password == "user123") {
                    menuUser(dataNasabah, panjang, &Kesalahan);
                    break;
                } else {
                    kesalahanLogin++;
                    cout << "Username atau password salah. Kesalahan ke-" << kesalahanLogin << endl;
                }
            }

            if (kesalahanLogin >= 3) {
                cout << "Anda melakukan 3 kali kesalahan login. Program dihentikan" << endl;
                return 0;   
            }
        } else if (pilihan == 0) {
            cout << "Terimakasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
            Kesalahan++;
            if (Kesalahan >= 3) {
                cout << "Anda melakukan 3 kali kesalahan login. Program dihentikan" << endl;
                return 0;  
            }
        }
    }
    return 0;
}

// Implementasi Bubble Sort untuk sorting nama (ascending)
void bubbleSortNama(Nasabah arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].nama > arr[j+1].nama) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Implementasi Selection Sort untuk sorting saldo (descending)
void selectionSortSaldo(Nasabah arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int max_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].saldo > arr[max_idx].saldo) {
                max_idx = j;
            }
        }
        swap(arr[max_idx], arr[i]);
    }
}

// Implementasi Insertion Sort untuk sorting nomor rekening (ascending)
void insertionSortNomorRekening(Nasabah arr[], int n) {
    for (int i = 1; i < n; i++) {
        Nasabah key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].nomorRekening > key.nomorRekening) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void buatRekening(Nasabah* data, int* size) {
    if (*size >= MAX_NASABAH) {
        cout << "Maaf jumlah nasabah sudah penuh. Tidak dapat menambahkan rekening baru." << endl;
    } else {
        string nama, nomorRekening;
        cout << "Masukkan nama nasabah : ";
        cin >> nama;
        cout << "Masukkan nomor rekening : ";
        cin >> nomorRekening;
        
        bool nomorSudahDigunakan = false;
        for (int i = 0; i < *size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                nomorSudahDigunakan = true;
                break;
            }
        }

        if (nomorSudahDigunakan) {
            cout << "Nomor rekening sudah digunakan. Tidak dapat membuat rekening baru." << endl;
        } else {
            data[*size].nama = nama;
            data[*size].nomorRekening = nomorRekening;
            data[*size].saldo = 0;
            (*size)++;
            cout << "Rekening berhasil dibuat." << endl;
        }
    }
}

void hapusRekening(Nasabah* data, int* size) {
    if (*size == 0) {
        cout << "Belum ada rekening yang terdaftar" << endl;     
    } else {
        string nomorRekening;
        cout << "Masukkan nomor rekening yang ingin dihapus: " ;
        cin >> nomorRekening;

        bool ditemukan = false;
        for (int i = 0; i < *size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                for (int j = i; j < *size - 1; j++) {
                    data[j] = data[j + 1];
                }
                (*size)--;
                ditemukan = true;
                cout << "Rekening berhasil dihapus." << endl;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan." << endl;
        }
    }
}

void tampilkanRekening(Nasabah* data, int size, int sortMethod) {
    if (size == 0) {
        cout << "Belum ada rekening yang terdaftar." << endl;
    } else {
        // Membuat salinan data untuk diurutkan
        Nasabah sortedData[MAX_NASABAH];
        for (int i = 0; i < size; i++) {
            sortedData[i] = data[i];
        }

        // Metode sorting
        switch (sortMethod) {
            case 1: // Bubble Sort by Nama (A-Z)
                bubbleSortNama(sortedData, size);
                break;
            case 2: // Selection Sort by Saldo (Descending)
                selectionSortSaldo(sortedData, size);
                break;
            case 3: // Insertion Sort by Nomor Rekening (Ascending)
                insertionSortNomorRekening(sortedData, size);
                break;
            default: // Tidak diurutkan (sortMethod = 0)
                break;
        }

        cout << "<====================================================================>" << endl;
        cout << "      |                      DAFTAR NASABAH                    |       " << endl;
        cout << "<====================================================================>" << endl;
        for (int i = 0; i < size; i++) {
            cout << "     | " << i + 1 <<  ". Nama : " << sortedData[i].nama
                << " | Nomor Rekening : " << sortedData[i].nomorRekening
                << " | Saldo : Rp." << sortedData[i].saldo << endl;
        }
        cout << "<====================================================================>"<<endl;
    }
}

void updateRekening(Nasabah* data, int size) {
    if (size == 0) {
        cout << "Belum ada rekening yang terdaftar." << endl;
    } else {
        string nomorRekening;
        cout << "Masukkan nomor rekening yang ingin diupdate : ";
        cin >> nomorRekening;

        bool ditemukan = false;
        for (int i = 0; i < size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                cout << "Masukkan nama baru : ";
                cin >> data[i].nama;
                cout << "Masukkan nomor rekening baru : ";
                cin >> data[i].nomorRekening;
                cout << "Rekening berhasil diupdate." << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan." << endl;
        }
    }
}

void cekSaldo(const Nasabah* data, int size) {
    if (size == 0) {
        cout << "Belum ada rekening yang terdaftar." << endl;
    } else {
        string nomorRekening;
        cout << "Masukkan nomor rekening : ";
        cin >> nomorRekening;

        bool ditemukan = false;
        for (int i = 0; i < size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                cout << "Nama : " << data[i].nama;
                cout << "Nomor Rekening : " << data[i].nomorRekening << endl;
                cout << "Saldo : Rp. " << data[i].saldo << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan." << endl;
        }
    }
}

void isiSaldo(Nasabah* data, int size) {
    if (size == 0) {
        cout << "Belum ada rekening yang terdaftar." << endl;
    } else {
        string nomorRekening;
        int jumlah;
        cout << "Masukkan nomor rekening : ";
        cin >> nomorRekening;
        cout << "Masukkan jumlah saldo yang ingin diisi : Rp.";
        cin >> jumlah;

        bool ditemukan = false;
        for (int i = 0; i < size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                data[i].saldo += jumlah;
                cout << "Saldo berhasil diisi! Saldo Anda sekarang : Rp." << data[i].saldo << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan." << endl;
        }
    }
}

void tarikSaldo(Nasabah* data, int size) {
    if (size == 0) {
        cout << "Belum ada rekening yang terdaftar." << endl;
    } else {
        string nomorRekening;
        int jumlah;
        cout << "Masukkan nomor rekening : ";
        cin >> nomorRekening;
        cout << "Masukkan jumlah saldo yang ingin diambil : Rp.";
        cin >> jumlah;

        bool ditemukan = false;
        for (int i = 0; i < size; i++) {
            if (data[i].nomorRekening == nomorRekening) {
                if (data[i].saldo >= jumlah) {
                    data[i].saldo -= jumlah;
                    cout << "Saldo berhasil diambil! Saldo Anda sekarang : Rp." << data[i].saldo << endl;
                } else {
                    cout << "Saldo tidak cukup." << endl;
                }
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan." << endl;
        }
    }
}

void menuAdmin(Nasabah* data, int* size, int* errors) {
    while (true) {
        cout << "<====================================================================>" << endl;
        cout << "      |                       MENU ADMIN                       |       " << endl;
        cout << "<====================================================================>" << endl;
        cout << "      |                1. Buat Rekening                        |       " << endl;
        cout << "      |                2. Hapus Rekening                       |       " << endl;
        cout << "      |                3. Tampilkan Rekening                   |       " << endl;
        cout << "      |                4. Update Rekening                      |       " << endl;
        cout << "      |                0. Kembali ke Menu Utama                |       " << endl;
        cout << "<====================================================================>" << endl;

        int pilihanAdmin;
        cout << "Pilih Menu: ";
        cin >> pilihanAdmin;

        switch (pilihanAdmin) {
            case 1:
                buatRekening(data, size);
                break;
            case 2:
                hapusRekening(data, size);
                break;
            case 3: {
                int sortMethod = 0;
                cout << "Pilih yang akan disorting (Pilih 0: Tidak sorting, Pilih 1: Nama A-Z, Pilih 2: Saldo, Pilih 3: No.Rek): ";
                cin >> sortMethod;
                tampilkanRekening(data, *size, sortMethod);
                break;
            }
            case 4:
                updateRekening(data, *size);
                break;
            case 0:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
                (*errors)++;
                if (*errors >= 3) {
                    cout << "Anda gagal sebanyak 3 kali, program dihentikan." << endl;
                    exit(0);
                }
        }
    }
}

void menuUser(Nasabah* data, int size, int* errors) {
    while (true) {
        cout << "<====================================================================>" << endl;
        cout << "      |                       MENU USER                       |       " << endl;
        cout << "<====================================================================>" << endl;
        cout << "      |                      1. Cek Saldo                     |       " << endl;
        cout << "      |                      2. isi Saldo                     |       " << endl;
        cout << "      |                      3. Tarik Saldo                   |       " << endl;
        cout << "      |                      0. Kembali Ke Menu Utama         |       " << endl;
        cout << "<====================================================================>" << endl;
        
        int pilihanUser;
        cout << "Pilih Menu User :";
        cin >> pilihanUser;

        switch (pilihanUser) {
            case 1:
                cekSaldo(data, size);
                break;
            case 2:
                isiSaldo(data, size);
                break;
            case 3:
                tarikSaldo(data, size);
                break;
            case 0:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
                (*errors)++;
                if (*errors >= 3) {
                    cout << "Anda gagal sebanyak 3 kali, program dihentikan." << endl;
                    exit(0);
                }
        }
    }
}