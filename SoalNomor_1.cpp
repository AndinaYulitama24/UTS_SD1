#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama,jenis;        
    int umur, darurat, urutanMasuk;    
};

class AntreanRumahSakit {
private:
    Pasien* antrean;    
    int kapasitas, jumlahPasien, counterUrutan;  

public:
    AntreanRumahSakit(int maxPasien) {
        kapasitas = maxPasien;
        antrean = new Pasien[kapasitas];  
        jumlahPasien = 0;                 
        counterUrutan = 0;                
    }
    
    ~AntreanRumahSakit() {
        delete[] antrean;  
    }
    
    void tambahPasien(string nama, string jenis, int umur, int darurat) {
        if (jumlahPasien < kapasitas) {
            antrean[jumlahPasien].nama = nama;
            antrean[jumlahPasien].jenis = jenis;
            antrean[jumlahPasien].umur = umur;
            antrean[jumlahPasien].darurat = darurat;
            antrean[jumlahPasien].urutanMasuk = ++counterUrutan;  
            jumlahPasien++;  
        } else {
            cout << "Antrean penuh!" << endl;
        }
    }
    
    void tukar(Pasien& a, Pasien& b) {
        Pasien temp = a;
        a = b;
        b = temp;
    }
    
    void urutkanAntrean() {
        for (int i = 0; i < jumlahPasien - 1; i++) {
            for (int j = 0; j < jumlahPasien - i - 1; j++) {
                if (antrean[j].darurat < antrean[j + 1].darurat) {
                    tukar(antrean[j], antrean[j + 1]);  
                }
                else if (antrean[j].darurat == antrean[j + 1].darurat) {
                    if (antrean[j].urutanMasuk > antrean[j + 1].urutanMasuk) {
                        tukar(antrean[j], antrean[j + 1]);
                    }
                }
            }
        }
    }
    
    void tampilkanAntrean() {
        for (int i = 0; i < jumlahPasien; i++) {
            cout << i + 1 << ". " << antrean[i].nama 
                 << " (" << antrean[i].umur << " tahun) - Darurat " 
                 << antrean[i].darurat << endl;
        }
    }
    
    void tampilkanSemuaPasien() {
        for (int i = 0; i < jumlahPasien; i++) {
            cout << "Pasien " << i + 1 << ":" << endl;
            cout << "  Nama: " << antrean[i].nama << endl;
            cout << "  Jenis: " << antrean[i].jenis << endl;
            cout << "  Umur: " << antrean[i].umur << " tahun" << endl;
            cout << "  Darurat: " << antrean[i].darurat << endl;
            cout << "  Urutan Masuk: " << antrean[i].urutanMasuk << endl;
            cout << endl;
        }
    }
};

int main() {
    int jumlahPasien;
    
    cout << "Petualangan Alya di Antrean Ajaib Rumah Sakit Hewan" << endl;
    cout << "Masukkan jumlah pasien: ";
    cin >> jumlahPasien;

    AntreanRumahSakit rumahSakit(jumlahPasien);
    
    for (int i = 0; i < jumlahPasien; i++) {
        string nama, jenis;
        int umur, darurat;
        
        cout << "\nPasien " << (i + 1) << ":" << endl;
        cout << "Nama hewan: ";
        cin >> nama;  
        cout << "Jenis hewan: ";
        cin >> jenis;
        cout << "Umur: "; 
        cin >> umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> darurat;
        
        if (darurat < 1 || darurat > 5) {
            cout << "Tingkat darurat harus antara 1-5! Menggunakan nilai default 1." << endl;
            darurat = 1;  
        }
        
        rumahSakit.tambahPasien(nama, jenis, umur, darurat);
    }
    
    rumahSakit.urutkanAntrean();
    rumahSakit.tampilkanAntrean();
    
    return 0;
}