#include <iostream>
#include <string>
using namespace std;

#define MAX_NASABAH 2

struct Nasabah {
    string nama;
    string nomorRekening;
    int saldo;
};

Nasabah dataNasabah[MAX_NASABAH];
int panjang = 0;
int Kesalahan = 0;

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
                            case 1: //Membuat rekening//
                                if (panjang >= MAX_NASABAH) {
                                    cout << "Maaf jumlah nasabah sudah penuh. Tidak dapat menambahkan rekening baru." << endl;
                                } else {
                                    string nama, nomorRekening;
                                    cout << "Masukkan nama nasabah : ";
                                    cin >> nama;
                                    cout << "Masukkan nomor rekening : ";
                                    cin >> nomorRekening;
                                    
                                    bool nomorSudahDigunakan = false;
                                    for (int i = 0; i < panjang; i++) {
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            nomorSudahDigunakan = true;
                                            break;
                                        }
                                    }

                                    if (nomorSudahDigunakan) {
                                        cout << "Nomor rekening sudah digunakan. Tidak dapat membuat rekening baru." << endl;
                                    } else {
                                        dataNasabah[panjang].nama = nama;
                                        dataNasabah[panjang].nomorRekening = nomorRekening;
                                        dataNasabah[panjang].saldo = 0;
                                        panjang++;
                                        cout << "Rekening berhasil dibuat." << endl;
                                    }
                                }
                                break;

                            case 2: //Menghapus rekening//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar." << endl;
                                } else {
                                    string nomorRekening;
                                    cout << "Masukkan nomor rekening yang ingin dihapus : ";
                                    cin >> nomorRekening;

                                    bool ditemukan = false;
                                    for (int i = 0; i < panjang; i++) {
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            for (int j = i; j < panjang - 1; j++) {
                                                dataNasabah[j] = dataNasabah[j + 1];
                                            }
                                            panjang--;
                                            ditemukan = true;
                                            cout << "Rekening berhasil dihapus." << endl;
                                            break;
                                        }
                                    }

                                    if (!ditemukan) {
                                        cout << "Nomor rekening tidak ditemukan." << endl;
                                    }
                                }
                                break;

                            case 3: //Menampilkan daftar rekening//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar.";
                                } else {
                                    cout << "<====================================================================>" << endl;
                                    cout << "      |                      DAFTAR NASABAH                    |       " << endl;
                                    cout << "<====================================================================>" << endl;
                                    for (int i = 0; i < panjang; i++) {
                                        cout << "     | " << i + 1 <<  ". Nama : " << dataNasabah[i].nama
                                             << " | Nomor Rekening : " << dataNasabah[i].nomorRekening
                                             << " | Saldo : Rp." << dataNasabah[i].saldo << endl;
                                    }
                                    cout << "<====================================================================>"<<endl;
                                }
                                break;
                            
                            case 4: //Pilihan untuk mengupdate rekening, seperti mengubah nama dan nomor rekening yang sudah terdaftar sebelumnya//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar." << endl;
                                } else {
                                    string nomorRekening;
                                    cout << "Masukkan nomor rekening yg ingin anda update : ";
                                    cin >> nomorRekening;

                                    bool ditemukan = false;
                                    for (int i = 0; i <panjang; i++) {
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            cout << "Masukkan nama baru : ";
                                            cin >> dataNasabah[i].nama;
                                            cout << "Masukkan nomor rekening baru : ";
                                            cin >> dataNasabah[i].nomorRekening;
                                            cout << "Rekening berhasil diupdate." << endl;
                                            ditemukan = true;
                                            break;
                                        }
                                    }

                                    if (!ditemukan) {
                                        cout << "Nomor rekening tidak ditemukan." << endl;
                                    }
                                }
                                break;

                            case 0: //Kembali ke menu utama//
                                break;

                            default:
                                cout << "Pilihan tidak valid." << endl;
                                Kesalahan++;
                                if (Kesalahan >= 3) {
                                    cout << "Anda gagal sebanyak 3 kali, program dihentikan." << endl;
                                    return 0;   
                                }
                        }

                        if (pilihanAdmin == 0) break;
                    }
                    break;
                } else {
                    kesalahanLogin++;
                    cout << "Username atau password salah. Kesalahan ke-" << kesalahanLogin << "." << endl;
                }
            }

            if (kesalahanLogin >= 3) {
                cout << "Anda melakukan 3 kali kesalahan login. Program dihentikan." << endl;
                return 0;
            }
        } else if (pilihan == 2) {
            string username, password;
            int kesalahanLogin = 0;

            while (kesalahanLogin < 3) {
                cout << "Masukkan username : ";
                cin >> username;
                cout << "Masukkan password : ";
                cin >> password;

                if (username == "user" && password == "user123") {
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
                            case 1: //Cek saldo yg ada didalam rekening//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar." << endl;
                                } else {
                                    string nomorRekening;
                                    cout << "Masukkan nomor rekening : ";
                                    cin >> nomorRekening;

                                    bool ditemukan = false;
                                    for (int i = 0; i < panjang; i++) {
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            cout << "Nama : " << dataNasabah[i].nama;
                                            cout << "Nomor Rekening : " << dataNasabah[i].nomorRekening << endl;
                                            cout << "Saldo : " << dataNasabah[i].saldo << endl;
                                            ditemukan = true;
                                            break;
                                        }

                                    }

                                    if (!ditemukan) {
                                        cout << "Nomor rekening tidak ditemukan." << endl;

                                    }
                                }
                                break;

                            case 2: //Mengisi saldo//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar." << endl;
                                } else {
                                    string nomorRekening;
                                    int jumlah;
                                    cout << "Masukkan nomor rekening : ";
                                    cin >> nomorRekening;
                                    cout << "Masukkan jumlah saldo yg ingin diisi : Rp.";
                                    cin >> jumlah;

                                    bool ditemukan = false;
                                    for (int i= 0; i < panjang; i++){
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            dataNasabah[i].saldo += jumlah;
                                            cout << "Saldo berhasil diisi! Saldo anda sekarang : Rp." << dataNasabah[i].saldo << endl;
                                            ditemukan = true;
                                            break;

                                        }
                                    }

                                    if (!ditemukan) {
                                        cout << "Nomor rekening tidak ditemukan." << endl;
                                    }
                                }
                                break;

                            case 3: //Menarik saldo//
                                if (panjang == 0) {
                                    cout << "Belum ada rekening yang terdaftar." << endl;
                                } else {
                                    string nomorRekening;
                                    int jumlah;
                                    cout << "Masukkan nomor rekening :";
                                    cin >> nomorRekening;
                                    cout << "Masukkan jumlah saldo yg ingin anda tarik : Rp.";
                                    cin >> jumlah;

                                    bool ditemukan = false;
                                    for (int i = 0; i < panjang; i++) {
                                        if (dataNasabah[i].nomorRekening == nomorRekening) {
                                            if (dataNasabah[i].saldo >=jumlah) {
                                                dataNasabah[i].saldo -=jumlah;
                                                cout << "Saldo berhasil ditarik! Saldo anda sekarang : Rp." << dataNasabah[i].saldo << endl;
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
                                break;

                            case 0: //Kembali ke menu utama//
                                break;

                            default:
                                cout << "Pilihan tidak valid." << endl;
                                Kesalahan++;
                                if (Kesalahan >= 3) {
                                    cout << "Anda gagal sebanyak 3 kali, program dihentikan." << endl;
                                    return 0;
                                }
                        }

                        if (pilihanUser == 0) break;
                    }
                    break;
                } else {
                    kesalahanLogin++;
                    cout << "Username atau password salah. Kesalahan ke -" << kesalahanLogin << endl;
                }
            }

            if (kesalahanLogin >= 3) {
                cout << "Anda melakukan 3 kali kesalahan login. Program dihentikan." << endl;
                return 0;
            }
        } else if (pilihan ==0) {
            cout << "Terimakasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
            Kesalahan++;
            if (Kesalahan >= 3) {
                cout << "Anda gagal sebanyak 3 kali, program dihentikan." << endl;
                return 0;
            }
        }
    }
    return 0;
}