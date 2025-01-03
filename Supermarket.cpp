#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Barang
{
public:
    string nama;
    int harga;

    Barang(string n, int h) : nama(n), harga(h) {}
};

void tampilkanBarang(const vector<Barang> &barang)
{
    cout << "\nDaftar Barang yang Tersedia:\n";
    for (int i = 0; i < barang.size(); ++i)
    {
        cout << i + 1 << ". " << barang[i].nama << " - Rp. " << barang[i].harga << endl;
    }
}

int main()
{
    vector<Barang> barangTersedia = {
        Barang("Sabun Mandi", 5000),
        Barang("Shampoo", 15000),
        Barang("Pasta Gigi", 8000),
        Barang("Mie Instan", 4000),
        Barang("Biskuit", 12000),
        Barang("Teh Botol", 7000),
        Barang("Susu", 15000),
        Barang("Kopi", 10000),
        Barang("Detergen", 18000),
        Barang("Tissue", 5000)};

    vector<Barang> keranjang;
    int totalHarga = 0;
    int uangMasuk = 0;
    int pilihan = 0;
    char kembali = 'Y';

    cout << "Selamat datang di Supermarket!\n";

    while (kembali == 'Y' || kembali == 'y')
    {
        tampilkanBarang(barangTersedia);
        cout << "\nPilih barang (1-10) untuk ditambahkan ke keranjang (0 untuk selesai): ";

        while (!(cin >> pilihan))
        {
            cout << "Input tidak valid. Silakan masukkan angka yang valid (1-10 atau 0 untuk selesai): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (pilihan >= 1 && pilihan <= 10)
        {
            keranjang.push_back(barangTersedia[pilihan - 1]);
            totalHarga += barangTersedia[pilihan - 1].harga;
            cout << "\nAnda telah memilih: " << barangTersedia[pilihan - 1].nama << endl;
        }
        else if (pilihan == 0)
        {
            if (!keranjang.empty())
            {
                cout << "\n\nBarang yang Anda pilih:\n";
                for (const Barang &b : keranjang)
                {
                    cout << b.nama << " - Rp. " << b.harga << endl;
                }
                cout << "\nTotal Harga: Rp. " << totalHarga << endl;

                cout << "\nMasukkan uang Anda: Rp. ";
                while (!(cin >> uangMasuk))
                {
                    cout << "Input tidak valid. Silakan masukkan uang yang valid: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (uangMasuk < totalHarga)
                {
                    cout << "\nUang tidak cukup! Total harga: Rp. " << totalHarga << ", tetapi Anda hanya membayar Rp. " << uangMasuk << endl;
                }
                else
                {
                    int kembalian = uangMasuk - totalHarga;
                    cout << "\nPembayaran berhasil! Kembalian Anda: Rp. " << kembalian << endl;
                    cout << "\nTerima kasih telah berbelanja!\n";
                }

                cout << "\nApakah Anda ingin kembali berbelanja atau keluar (Y/y untuk kembali, N/n untuk keluar): ";
                cin >> kembali;
                while (!(kembali == 'Y' || kembali == 'y' || kembali == 'N' || kembali == 'n'))
                {
                    cout << "Input tidak valid. Silakan masukkan Y/y untuk kembali atau N/n untuk keluar: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> kembali;
                }

                if (kembali == 'Y' || kembali == 'y')
                {
                    keranjang.clear();
                    totalHarga = 0;
                }
                else if (kembali == 'N' || kembali == 'n')
                {
                    cout << "\nTerima kasih dan sampai jumpa!\n";
                    break;
                }
            }
            else
            {
                cout << "Anda tidak memilih barang apapun.\n";
                cout << "Apakah Anda ingin kembali berbelanja atau keluar (Y/y untuk kembali, N/n untuk keluar): ";
                cin >> kembali;
            }
        }
        else
        {
            cout << "\nBarang yang Anda inputkan tidak ada. Pilihlah barang dengan nomor yang valid (1-10).\n\n";
            cout << "Apakah Anda ingin kembali berbelanja atau keluar (Y/y untuk kembali, N/n untuk keluar): ";
            cin >> kembali;
        }
    }

    return 0;
}
