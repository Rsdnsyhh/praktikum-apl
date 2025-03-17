#include <iostream>
#include <string>
using namespace std;

#define MAX_NASABAH 2
string Data_Rekening_Nasabah[MAX_NASABAH][10];
int Saldo[MAX_NASABAH] = {0};

int panjang = 0;
int Kesalahan = 0;

void tampilkanMenuUtama() {
    cout << "<====================================================================>" << endl;
    cout << "      |        SELAMAT DATANG DIPROGRAM BANK SEDERHANA         |       " << endl;
    cout << "<====================================================================>" << endl;
    cout << "      |                1. Login Sebagai Admin                  |       " << endl;
    cout << "      |                2. Login Sebagai User                   |       " << endl;
    cout << "      |                     0. Keluar                          |       " << endl;
    cout << "<====================================================================>" << endl;
}

void tampilkanMenuAdmin() {
    cout << "<====================================================================>" << endl;
    cout << "      |                       MENU ADMIN                       |       " << endl;
    cout << "<====================================================================>" << endl;
    cout << "      |                 1. Buat Rekening                       |       " << endl;
    cout << "      |                 2. Hapus Rekening                      |       " << endl;
    cout << "      |                 3. Tampilkan Rekening Nasabah          |       " << endl;
    cout << "      |                 0. Kembali Ke Menu Utama               |       " << endl;
    cout << "<====================================================================>" << endl;
}

void tampilkanMenuUser() {
    cout << "<====================================================================>" << endl;
    cout << "      |                       MENU USER                        |       " << endl;
    cout << "<====================================================================>" << endl;
    cout << "      |                     1. Cek Saldo                       |       " << endl;
    cout << "      |                     2. Isi Saldo                       |       " << endl;
    cout << "      |                     3. Tarik Saldo                     |       " << endl;
    cout << "      |                     0. Kembali Ke Menu Utama           |       " << endl;
    cout << "<====================================================================>" << endl;
}

void buatRekening() {
    if (panjang >= MAX_NASABAH) {
        cout << "Maaf, jumlah nasabah sudah penuh. Tidak dapat menambahkan rekening baru." << endl;
        return;
    }
        string Nama_Nasabah, Nomor_Rekening;
        cout << "Masukkan nama nasabah: ";
        cin >> Nama_Nasabah;
        cout << " Masukkan nomor rekening: ";
        cin >> Nomor_Rekening;
        
        for (int i = 0 ; i < panjang; i++) {
            if (Data_Rekening_Nasabah[i][1] == Nomor_Rekening) {
                cout << "Nomor rekening sudah digunakan. Tidak dapat membuat rekening baru." << endl;
                return;
            }
        }

        Data_Rekening_Nasabah[panjang][0] = Nama_Nasabah;
        Data_Rekening_Nasabah[panjang][1] = Nomor_Rekening;
        Saldo[panjang] = 0;
        panjang++;
        cout << "Rekening berhasil dibuat." << endl;
}

void hapusRekening() {
    if (panjang == 0) {
        cout << "Belum ada rekening yang terdaftar.\n";
    } else {
        string Nomor_Rekening;
        cout << "Masukkan nomor rekening yang akan dihapus: ";
        cin >> Nomor_Rekening;

        int ditemukan = 0;
        for (int i = 0; i < panjang; i++) {
            if (Data_Rekening_Nasabah[i][1] == Nomor_Rekening) {
                for (int j = i; j < panjang - 1; j++) {
                    Data_Rekening_Nasabah[j][0] = Data_Rekening_Nasabah[j + 1][0];
                    Data_Rekening_Nasabah[j][1] = Data_Rekening_Nasabah[j + 1][1];
                    Saldo[j] = Saldo[j + 1];
                }
                panjang--;
                ditemukan = 1;
                cout << "Rekening berhasil dihapus." << endl;
                break;
            }
        }

        if (ditemukan == 0) {
            cout << "Nomor rekening tidak ditemukan.\n";
        }
    }
}

void tampilkanNasabah() {
    if (panjang == 0) {
        cout << "Belum ada rekening yang terdaftar.\n";
    } else {
        cout << "<====================================================================>\n";
        cout << "      |                      DAFTAR NASABAH                    |       \n";
        cout << "<====================================================================>\n";
        for (int i = 0; i < panjang; i++) {
            cout << "      | " << i + 1 << ". Nama: " << Data_Rekening_Nasabah[i][0]
            << "      | Nomor Rekening: " << Data_Rekening_Nasabah[i][1]
            << "      | Saldo : Rp. " << Saldo [i] << "\n";
        }
        cout << "<====================================================================>\n";
    }
}

void cekSaldo() {
    if (panjang == 0) {
        cout << "Belum ada rekening yang terdaftar.\n";
    } else {
        string Nomor_Rekening;
        cout << "Masukkan nomor rekening: ";
        cin >> Nomor_Rekening;

        int ditemukan = 0;
        for (int i = 0; i < panjang; i++) {
            if (Data_Rekening_Nasabah[i][1] == Nomor_Rekening) {
                cout << "Nama nasabah: " << Data_Rekening_Nasabah[i][0] << "\n";
                cout << "Nomor rekening: " << Data_Rekening_Nasabah[i][1] << "\n";
                cout << "Saldo: Rp." << Saldo[i] << "\n";
                ditemukan = 1;
                break;
            }
        }
        if (!ditemukan) {
            cout << "Nomor rekening tidak ditemukan.\n";
        }
    }
}

void isiSaldo() {
    if (panjang == 0) {
        cout << "Belum ada rekening yang terdaftar.\n";
    } else {
        string Nomor_Rekening;
        int jumlah;
        cout << "Masukkan nomor rekening: ";
        cin >> Nomor_Rekening;
        cout << "Masukkan jumlah saldo yang ingin diisi: Rp. ";
        cin >> jumlah;

        int ditemukan = 0;
        for (int i = 0; i < panjang; i++) {
            if (Data_Rekening_Nasabah[i][1] == Nomor_Rekening) {
                Saldo[i] += jumlah;
                cout << "Saldo berhasil diisi! Saldo anda sekarang: Rp." << Saldo[i] << "\n";
                ditemukan = 1;
                break;
            }
        }
        if (ditemukan == 0) {
            cout << "Nomor rekening tidak ditemukan.\n";
        }
    }
}

void tarikSaldo() {
    if (panjang == 0) {
        cout << "Belum ada rekening yang terdaftar.\n";
    } else {
        string Nomor_Rekening;
        int jumlah;
        cout << "Masukkan nomor rekening: ";
        cin >> Nomor_Rekening;
        cout << "Masukkan jumlah saldo yang ingin ditarik: Rp. ";
        cin >> jumlah;

        int ditemukan = 0;
        for (int i = 0; i < panjang; i++) {
            if (Data_Rekening_Nasabah[i][1] == Nomor_Rekening) {
                if (Saldo[i] >= jumlah) {
                    Saldo[i] -= jumlah;
                    cout << "Saldo berhasil ditarik! Saldo anda sekarang: Rp." << Saldo[i] << "\n";

                } else {
                    cout << "Saldo tidak cukup.\n";
                }
                ditemukan = 1;
                break;
            }
        }
        if (ditemukan == 0) {
            cout << "Nomor rekening tidak ditemukan.\n";
        }
    }
}

int login(string role) {
    string username, password;
    int kesalahanLogin = 0;

    while (kesalahanLogin < 3) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (role == "admin" && username == "admin" && password == "admin123") {
            return 1;
        } else if (role == "user" && username == "user" && password == "user123") {
            return 1;
        } else {
            kesalahanLogin++;
            cout << "Username atau password salah. Kesalahan ke-" << kesalahanLogin << ".\n";
        }
    }

    cout << "Anda telah melakukan 3 kali kesalahan login. Program dihentikan.\n";
    return 0;
}
int main() {
    while (true) {
        tampilkanMenuUtama();
        int pilihan;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (login("admin")){
                while (true) {
                    tampilkanMenuAdmin();
                    int pilihanAdmin;
                    cout << "Pilih Menu Admin: ";
                    cin >> pilihanAdmin;

                    switch (pilihanAdmin) {
                        case 1:
                            buatRekening();
                            break;
                        case 2:
                            hapusRekening();
                            break;
                        case 3:
                            tampilkanNasabah();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid.\n";
                            Kesalahan++;
                            if (Kesalahan >= 3) {
                                cout << "Anda telah melakukan 3 kali kesalahan. Program dihentikan.\n";
                                return 0;
                            }
                    }

                    if (pilihanAdmin == 0) break;
                    }  
                 } else {
                    return 0;
                }
            } else if (pilihan == 2) {
                if (login("user")) {
                    while (true) {
                        tampilkanMenuUser();
                        int pilihanUser;
                        cout << "Pilih Menu User: ";
                        cin >> pilihanUser;

                        switch (pilihanUser) {
                            case 1:
                                cekSaldo();
                                break;
                            case 2:
                                isiSaldo();
                                break;
                            case 3:
                                tarikSaldo();
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Pilihan tidak valid.\n";
                                Kesalahan++;
                                if (Kesalahan >= 3) {
                                    cout << "Anda telah melakukan 3 kali kesalahan. Program dihentikan.\n";
                                    return 0;
                                }
                        }

                        if (pilihanUser == 0) break;
                    }
                } else {
                    return 0;   
                }
            } else if (pilihan == 0) {
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            } else {
                cout << "Pilihan tidak valid.\n";
                Kesalahan++;
                if (Kesalahan >= 3) {
                    cout << "Anda telah melakukan 3 kali kesalahan. Program dihentikan.\n";
            }
        }
    }
    return 0;
}