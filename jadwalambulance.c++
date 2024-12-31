#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct JadwalAmbulans {
    string tanggal;
    string waktu;
    string tujuan;
};

class PengelolaanJadwal {
private:
    vector<JadwalAmbulans> jadwalAmbulans;

public:
    void tambahJadwal() {
        JadwalAmbulans jadwalBaru;
        cout << "Masukkan tanggal (DD-MM-YYYY): ";
        cin >> jadwalBaru.tanggal;
        cout << "Masukkan waktu (HH:MM): ";
        cin >> jadwalBaru.waktu;
        cout << "Masukkan tujuan: ";
        cin.ignore(); // Mengabaikan newline dari input sebelumnya
        getline(cin, jadwalBaru.tujuan);

        jadwalAmbulans.push_back(jadwalBaru);
        cout << "Jadwal ambulans berhasil ditambahkan!" << endl;
    }

    void tampilkanJadwal() {
        cout << "\nJadwal Ambulans:\n";
        if (jadwalAmbulans.empty()) {
            cout << "Tidak ada jadwal ambulans yang terdaftar." << endl;
            return;
        }
        for (size_t i = 0; i < jadwalAmbulans.size(); i++) {
            cout << "Jadwal " << (i + 1) << ": "
                 << "Tanggal: " << jadwalAmbulans[i].tanggal
                 << ", Waktu: " << jadwalAmbulans[i].waktu
                 << ", Tujuan: " << jadwalAmbulans[i].tujuan << endl;
        }
    }

    void hapusJadwal() {
        int index;
        tampilkanJadwal();
        cout << "Masukkan nomor jadwal yang ingin dihapus: ";
        cin >> index;

        if (index < 1 || index > jadwalAmbulans.size()) {
            cout << "Nomor jadwal tidak valid." << endl;
            return;
        }

        jadwalAmbulans.erase(jadwalAmbulans.begin() + (index - 1));
        cout << "Jadwal ambulans berhasil dihapus!" << endl;
    }
};

int main() {
    PengelolaanJadwal pj;
    int pilihan;

    do {
        cout << "\nMenu Pengelolaan Jadwal Ambulans:\n";
        cout << "1. Tambah Jadwal Ambulans\n";
        cout << "2. Tampilkan Jadwal Ambulans\n";
        cout << "3. Hapus Jadwal Ambulans\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                pj.tambahJadwal();
                break;
            case 2:
                pj.tampilkanJadwal();
                break;
            case 3:
                pj.hapusJadwal();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}