#include <iostream>
using namespace std;

void TampilkanMenu(){
    cout << "<=================================>\n";
    cout << "\n      | PILIH MENU KONVERSI |     \n";
    cout << "<=================================>\n";
    cout << "1.Meter ke Centimeter, Mile, Foot\n";
    cout << "2.Centimeter ke Meter, Mile, Foot\n";
    cout << "3.Mile ke Meter, Centimeter, Foot\n";
    cout << "4.Foot ke Meter, Centimeter, Mile\n";
    cout << "5.KELUAR\n";
    cout << "<==================================>\n";
}

void KonversiDanTampilkan(double nilai, double keMeter, double keCentimeter, double keMile, double keFoot){
    cout << nilai << " = " << nilai * keMeter << " Meter\n";
    cout << nilai << " = " << nilai * keCentimeter << " Centimeter\n";
    cout << nilai << " = " << nilai * keMile << " Mile\n";
    cout << nilai << " = " << nilai * keFoot << " Foot\n";
}

int main () {
    string Nama, NIM;
    int salah = 0;


    while (salah < 3) {
        cout << "Masukkan Nama Anda : ";
        getline (cin, Nama);
        cout << "Masukkan NIM Anda : ";
        getline (cin, NIM);

        if (Nama == "Rusdiansyah" && NIM == "2409106013") {

            break;
        } else {
            salah++;
            cout << "Nama atau NIM anda salah, percobaan tersisa : " << 3 - salah << endl;
        }
    }

    if (salah == 3) {
        cout << "Anda salah sebanyak 3 kali, program dihentikan.\n";
        return 0;
    }

    while (true) {
        TampilkanMenu();
        int pilihan;
        cout << "Masukkan Pilihan (1-5) : ";
        cin >> pilihan;

        if (pilihan == 5) {
            cout << "Program Selesai. Terimakasih telah menggunakan program ini.\n";
            break;
        }

        double nilai;
        cout << "Masukkan Nilai : ";
        cin >> nilai;

        switch (pilihan) {
            case 1:
                KonversiDanTampilkan(nilai, 1, 100, 0.000189394, 3.28084);
                break;
            case 2:
                KonversiDanTampilkan(nilai, 0.01, 1, 0.000189394, 3.28084);
                break;
            case 3:
                KonversiDanTampilkan(nilai, 1609.34, 160934, 1, 5280);
                break;
            case 4:
                KonversiDanTampilkan(nilai, 0.3048, 30.48, 0.000189394, 1);
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
        }
    }

    return 0;
}