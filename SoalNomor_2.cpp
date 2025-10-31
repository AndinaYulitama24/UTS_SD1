#include <iostream>
#include <string>
using namespace std;
struct Film {
    string judul; int tahun, rating; Film* next;};
class DaftarFilm {
private:
    Film* head;   
    int total;   

public:
    DaftarFilm() {
        head = NULL;  
        total = 0;   
    }
    void tambahDepan(string judul, int tahun, int rating) {
        Film* baru = new Film();
        baru->judul = judul;
        baru->tahun = tahun;
        baru->rating = rating;
        baru->next = head;
        head = baru;
        total++; 
    }
    void tambahBelakang(string judul, int tahun, int rating) {
        Film* baru = new Film();
        baru->judul = judul;
        baru->tahun = tahun;
        baru->rating = rating;
        baru->next = NULL;  

        if (!head) {
            head = baru;  
        } else {
            Film* temp = head; 
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = baru; 
        }
        total++;  
    }
    
    void tambahSetelah(string setelah, string judul, int tahun, int rating) {
        
        Film* temp = head;
        while (temp && temp->judul != setelah) {
            temp = temp->next;
        }
        if (temp) {
            Film* baru = new Film();
            baru->judul = judul;
            baru->tahun = tahun;
            baru->rating = rating;
            baru->next = temp->next;
            temp->next = baru;
            total++; 
        } else {
            cout << "Film '" << setelah << "' tidak ditemukan!" << endl;
        }
    }
    void hapusFilm(string judul) {
        if (!head) return;

        if (head->judul == judul) {
            Film* hapus = head;      
            head = head->next;       
            delete hapus;            
            total--;                 
            return;
        }
        Film* temp = head;
        while (temp->next && temp->next->judul != judul) {
            temp = temp->next;
        }
        if (temp->next) {
            Film* hapus = temp->next;        
            temp->next = temp->next->next;   
            delete hapus;                   
            total--;                         
        } else {
            cout << "Film '" << judul << "' tidak ditemukan!" << endl;
        }
    }
    void tampilkan() {
        Film* temp = head; 
        while (temp) {
            cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
            temp = temp->next;  
        }
        cout << "Total film tersisa: " << total << endl;
    }
};

int main() {
    DaftarFilm harry;  
    int jumlah;
    cout << "Masukkan jumlah film awal: ";
    cin >> jumlah;
    for (int i = 0; i < jumlah; i++) {
        string judul;
        int tahun, rating;
        
        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        cin >> judul;    
        cout << "Tahun: ";
        cin >> tahun;   
        cout << "Rating: ";
        cin >> rating; 
        
        harry.tambahBelakang(judul, tahun, rating);
    }
    char pilih;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> pilih;

    if (pilih == 'y' || pilih == 'Y') {
        string hapusJudul;
        cout << "Masukkan judul film yang sudah ditonton: ";
        cin >> hapusJudul;
        harry.hapusFilm(hapusJudul);
    }
    harry.tampilkan();
    
    return 0;
}