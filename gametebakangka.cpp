#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    char mainLagi;

    do {
        srand(time(0));  // Seed angka random berdasarkan waktu
        int angka_rahasia = rand() % 100 + 1;
        int tebakan;
        vector<int> riwayat;
        bool benar = false;

        cout << "======================================\n";
        cout << "       Permainan Tebak Angka\n";
        cout << "======================================\n";
        cout << "Saya sudah memilih angka antara 1 - 100.\n";
        cout << "Silakan tebak sampai kamu benar!\n\n";
while (!benar) {
            cout << "Masukkan tebakanmu: ";
            cin >> tebakan;

            // Simpan riwayat tebakan
            riwayat.push_back(tebakan);

            if (tebakan > angka_rahasia) {
                cout << "Tebakanmu terlalu besar.\n";
            } else if (tebakan < angka_rahasia) {
                cout << "Tebakanmu terlalu kecil.\n";
            } else {
                cout << "\nSelamat! Kamu berhasil menebak angka " << angka_rahasia << " dengan " << riwayat.size() << " percobaan.\n";
                benar = true;
                break;
            }
// Bandingkan dengan tebakan sebelumnya jika ada lebih dari 1
            if (riwayat.size() > 1) {
                int jarak_sekarang = abs(tebakan - angka_rahasia);
                int jarak_sebelumnya = abs(riwayat[riwayat.size() - 2] - angka_rahasia);

                if (jarak_sekarang < jarak_sebelumnya) {
                    cout << "Kamu semakin dekat!\n";
                } else if (jarak_sekarang > jarak_sebelumnya) {
                    cout << "Kamu malah menjauh!\n";
                } else {
                    cout << "Tebakanmu sama jauhnya dengan sebelumnya.\n";
                }
            }
// Tampilkan semua tebakan sebelumnya
            cout << "Riwayat tebakan: ";
            for (int i = 0; i < riwayat.size(); ++i) {
                cout << riwayat[i];
                if (i != riwayat.size() - 1) cout << ", ";
            }
            cout << "\n\n";
        }

        // Tanya apakah ingin bermain lagi
        cout << "Ingin bermain lagi? (y/n): ";
        cin >> mainLagi;
        cout << "\n";

    } while (mainLagi == 'y' || mainLagi == 'Y');

    cout << "Terima kasih telah bermain. Sampai jumpa!\n";
    return 0;
}
