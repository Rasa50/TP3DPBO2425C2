#include "Person.cpp"
#include "TempatUsaha.cpp"
#include "Employee.cpp"
#include "Pengusaha.cpp"
#include "OwnerEmployee.cpp"
#include "Aula.cpp"
#include "GorOlahraga.cpp"
#include "TokoKue.cpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

// ============= FUNGSI CETAK =============
void cetakTabelTempat(vector<TempatUsaha*>& places) {
    if (places.empty()) {
        cout << "Belum ada data tempat usaha.\n";
        return;
    }
    
    cout << "\n" << string(100, '=') << endl;
    cout << left << setw(5) << "No" << setw(25) << "Nama Tempat" 
         << setw(12) << "No Izin" << setw(15) << "Kategori" 
         << setw(20) << "Lokasi" << setw(30) << "Deskripsi" << endl;
    cout << string(100, '=') << endl;
    
    for (size_t i = 0; i < places.size(); i++) {
        cout << left << setw(5) << i + 1
             << setw(25) << places[i]->getNamaTempat()
             << setw(12) << places[i]->getNoIzin()
             << setw(15) << places[i]->getKategoriUsaha()
             << setw(20) << places[i]->getLokasi()
             << setw(30) << places[i]->getDeskripsi() << endl;
    }
    cout << string(100, '=') << endl;
}

void cetakTabelEmployee(vector<Employee*>& employees) {
    if (employees.empty()) {
        cout << "Belum ada data employee.\n";
        return;
    }
    
    cout << "\n" << string(120, '=') << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Nama" 
         << setw(20) << "Alamat" << setw(6) << "Usia" << setw(12) << "Gender"
         << setw(15) << "Posisi" << setw(25) << "Email" 
         << setw(12) << "Gaji" << setw(25) << "Tempat Kerja" << endl;
    cout << string(120, '=') << endl;
    
    for (auto& emp : employees) {
        TempatUsaha* tempat = emp->getTempatKerja();
        cout << left << setw(5) << emp->getId()
             << setw(20) << emp->getNama()
             << setw(20) << emp->getAlamat()
             << setw(6) << emp->getUsia()
             << setw(12) << emp->getGender()
             << setw(15) << emp->getPosisi()
             << setw(25) << emp->getEmail()
             << setw(12) << (int)emp->getGaji()
             << setw(25) << (tempat ? tempat->getNamaTempat() : "-") << endl;
    }
    cout << string(120, '=') << endl;
}

void cetakTabelPengusaha(vector<Pengusaha*>& pengusaha) {
    if (pengusaha.empty()) {
        cout << "Belum ada data pengusaha.\n";
        return;
    }
    
    cout << "\n" << string(125, '=') << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Nama" 
         << setw(20) << "Alamat" << setw(6) << "Usia" << setw(12) << "Gender"
         << setw(20) << "Nama Bisnis" << setw(15) << "Tanggal Mulai" 
         << setw(15) << "Pendapatan" << setw(20) << "Tempat Usaha" << endl; // Kolom baru
    cout << string(125, '=') << endl;
    
    for (auto& p : pengusaha) {
        TempatUsaha* tempat = p->getTempatUsahaDimiliki();
        cout << left << setw(5) << p->getId()
             << setw(20) << p->getNama()
             << setw(20) << p->getAlamat()
             << setw(6) << p->getUsia()
             << setw(12) << p->getGender()
             << setw(20) << p->getNamaBisnis()
             << setw(15) << p->getStartUpDate()
             << setw(15) << (int)p->getPendapatan()
             << setw(20) << (tempat ? tempat->getNamaTempat() : "-") << endl; // Menampilkan nama tempat usaha
    }
    cout << string(125, '=') << endl;
}

void cetakTabelOwnerEmployee(vector<OwnerEmployee*>& ownerEmployees) {
    if (ownerEmployees.empty()) {
        cout << "Belum ada data owner-employee.\n";
        return;
    }
    
    cout << "\n" << string(140, '=') << endl;
    cout << left << setw(5) << "ID" << setw(18) << "Nama" 
         << setw(10) << "Usia" << setw(15) << "Posisi"
         << setw(12) << "Gaji" << setw(20) << "Nama Bisnis"
         << setw(15) << "Pendapatan" << setw(15) << "% Kepemilikan"
         << setw(20) << "Status Manajemen" << endl;
    cout << string(140, '=') << endl;
    
    for (auto& oe : ownerEmployees) {
        cout << left << setw(5) << oe->getIdOE()
             << setw(18) << oe->getNama()
             << setw(10) << oe->getUsia()
             << setw(15) << oe->getPosisi()
             << setw(12) << (int)oe->getGaji()
             << setw(20) << oe->getNamaBisnis()
             << setw(15) << (int)oe->getPendapatan()
             << setw(15) << oe->getPersentaseKepemilikan()
             << setw(20) << oe->getStatusManajemen() << endl;
    }
    cout << string(140, '=') << endl;
}


// ============= FUNGSI INPUT =============
void inputTempatUsaha(vector<TempatUsaha*>& places) {
    cout << "\n=== TAMBAH TEMPAT USAHA ===\n";
    cout << "Pilih Jenis:\n";
    cout << "1. Tempat Usaha Umum\n";
    cout << "2. Toko Kue\n";
    cout << "3. Aula\n";
    cout << "4. GOR Olahraga\n";
    cout << "Pilihan: ";
    
    int jenis;
    cin >> jenis;
    cin.ignore();
    
    string nama, noIzin, kategori, lokasi, deskripsi;
    
    cout << "Nama Tempat: "; getline(cin, nama);
    cout << "No Izin: "; getline(cin, noIzin);
    cout << "Kategori Usaha: "; getline(cin, kategori);
    cout << "Lokasi: "; getline(cin, lokasi);
    cout << "Deskripsi: "; getline(cin, deskripsi);
    
    if (jenis == 1) {
        TempatUsaha* t = new TempatUsaha();
        t->setNamaTempat(nama);
        t->setNoIzin(noIzin);
        t->setKategoriUsaha(kategori);
        t->setLokasi(lokasi);
        t->setDeskripsi(deskripsi);
        places.push_back(t);
    }
    else if (jenis == 2) {
        string namaProduk, jenisKue;
        int stok;
        cout << "Nama Produk: "; getline(cin, namaProduk);
        cout << "Jenis Kue: "; getline(cin, jenisKue);
        cout << "Stok: "; cin >> stok; cin.ignore();
        
        TokoKue* t = new TokoKue();
        t->setNamaTempat(nama);
        t->setNoIzin(noIzin);
        t->setKategoriUsaha(kategori);
        t->setLokasi(lokasi);
        t->setDeskripsi(deskripsi);
        // Tambahan setter untuk TokoKue
        places.push_back(t);
    }
    else if (jenis == 3) {
        double luas, hargaSewa;
        string kapasitas, fasilitas, tipe;
        cout << "Luas (m2): "; cin >> luas; cin.ignore();
        cout << "Kapasitas: "; getline(cin, kapasitas);
        cout << "Fasilitas: "; getline(cin, fasilitas);
        cout << "Harga Sewa: "; cin >> hargaSewa; cin.ignore();
        cout << "Tipe: "; getline(cin, tipe);
        
        Aula* a = new Aula();
        a->setNamaTempat(nama);
        a->setNoIzin(noIzin);
        a->setKategoriUsaha(kategori);
        a->setLokasi(lokasi);
        a->setDeskripsi(deskripsi);
        // Tambahan setter untuk Aula
        places.push_back(a);
    }
    else if (jenis == 4) {
        string jenisOlahraga, fasilitas, skala;
        double hargaSewa;
        cout << "Jenis Olahraga: "; getline(cin, jenisOlahraga);
        cout << "Fasilitas: "; getline(cin, fasilitas);
        cout << "Skala: "; getline(cin, skala);
        cout << "Harga Sewa: "; cin >> hargaSewa; cin.ignore();
        
        GorOlahraga* g = new GorOlahraga();
        g->setNamaTempat(nama);
        g->setNoIzin(noIzin);
        g->setKategoriUsaha(kategori);
        g->setLokasi(lokasi);
        g->setDeskripsi(deskripsi);
        // Tambahan setter untuk GorOlahraga
        places.push_back(g);
    }
    
    cout << "Tempat usaha berhasil ditambahkan!\n";
}

void inputEmployee(vector<Employee*>& employees, vector<TempatUsaha*>& places) {
    cout << "\n=== TAMBAH EMPLOYEE ===\n";
    
    Employee* emp = new Employee();
    
    int id, usia;
    string nama, alamat, gender, posisi, email;
    double gaji;
    
    cout << "ID: "; cin >> id; cin.ignore();
    emp->setId(id);
    
    cout << "Nama: "; getline(cin, nama);
    emp->setNama(nama);
    
    cout << "Alamat: "; getline(cin, alamat);
    emp->setAlamat(alamat);
    
    cout << "Usia: "; cin >> usia; cin.ignore();
    emp->setUsia(usia);
    
    cout << "Gender: "; getline(cin, gender);
    emp->setGender(gender);
    
    cout << "Posisi: "; getline(cin, posisi);
    emp->setPosisi(posisi);
    
    cout << "Email: "; getline(cin, email);
    emp->setEmail(email);
    
    cout << "Gaji: "; cin >> gaji; cin.ignore();
    emp->setGaji(gaji);
    
    // Pilih tempat kerja
    if (!places.empty()) {
        cout << "\nPilih Tempat Kerja:\n";
        for (size_t i = 0; i < places.size(); i++) {
            cout << i + 1 << ". " << places[i]->getNamaTempat() 
                 << " (" << places[i]->getKategoriUsaha() << ")\n";
        }
        cout << "0. Tidak ada\n";
        cout << "Pilihan: ";
        int pilih;
        cin >> pilih;
        cin.ignore();
        
        if (pilih > 0 && pilih <= (int)places.size()) {
            emp->setTempatKerja(places[pilih - 1]);
        }
    }
    
    employees.push_back(emp);
    cout << "Employee berhasil ditambahkan!\n";
}

void inputPengusaha(vector<Pengusaha*>& pengusaha, vector<TempatUsaha*>& places) {
    cout << "\n=== TAMBAH PENGUSAHA ===\n";
    
    Pengusaha* p = new Pengusaha();
    
    int id, usia;
    string nama, alamat, gender, namaBisnis, startUpDate;
    double pendapatan;
    
    cout << "ID: "; cin >> id; cin.ignore();
    p->setId(id);
    
    cout << "Nama: "; getline(cin, nama);
    p->setNama(nama);
    
    cout << "Alamat: "; getline(cin, alamat);
    p->setAlamat(alamat);
    
    cout << "Usia: "; cin >> usia; cin.ignore();
    p->setUsia(usia);
    
    cout << "Gender: "; getline(cin, gender);
    p->setGender(gender);
    
    cout << "Nama Bisnis: "; getline(cin, namaBisnis);
    p->setNamaBisnis(namaBisnis);
    
    cout << "Tanggal Mulai (dd-mm-yyyy): "; getline(cin, startUpDate);
    p->setStartUpDate(startUpDate);
    
    cout << "Pendapatan: "; cin >> pendapatan; cin.ignore();
    p->setPendapatan(pendapatan);
    
    // Pilih tempat usaha yang dimiliki
    if (!places.empty()) {
        cout << "\nPilih Tempat Usaha yang Dimiliki:\n";
        for (size_t i = 0; i < places.size(); i++) {
            cout << i + 1 << ". " << places[i]->getNamaTempat() 
                 << " (" << places[i]->getKategoriUsaha() << ")\n";
        }
        cout << "0. Tidak ada\n";
        cout << "Pilihan: ";
        int pilih;
        cin >> pilih;
        cin.ignore();
        
        if (pilih > 0 && pilih <= (int)places.size()) {
            p->setTempatUsahaDimiliki(places[pilih - 1]);
        }
    }
    
    pengusaha.push_back(p);
    cout << "Pengusaha berhasil ditambahkan!\n";
}

void inputOwnerEmployee(vector<OwnerEmployee*>& ownerEmployees, 
                        vector<Employee*>& employees, 
                        vector<Pengusaha*>& pengusaha) {
    cout << "\n=== TAMBAH OWNER-EMPLOYEE ===\n";
    
    if (employees.empty() || pengusaha.empty()) {
        cout << "Error: Harus ada data Employee dan Pengusaha terlebih dahulu!\n";
        return;
    }
    
    // Cari kecocokan data antara Employee dan Pengusaha (berdasarkan nama)
    cout << "\n--- Mencari Kecocokan Data ---\n";
    vector<pair<int, int>> matches; // pair<index_employee, index_pengusaha>
    
    for (size_t i = 0; i < employees.size(); i++) {
        for (size_t j = 0; j < pengusaha.size(); j++) {
            // Cek apakah nama, alamat, usia, dan gender sama
            if (employees[i]->getNama() == pengusaha[j]->getNama() &&
                employees[i]->getAlamat() == pengusaha[j]->getAlamat() &&
                employees[i]->getUsia() == pengusaha[j]->getUsia() &&
                employees[i]->getGender() == pengusaha[j]->getGender()) {
                matches.push_back(make_pair(i, j));
            }
        }
    }
    
    if (matches.empty()) {
        cout << "Tidak ada data yang cocok antara Employee dan Pengusaha!\n";
        cout << "Owner-Employee harus merupakan orang yang sama di kedua daftar.\n";
        cout << "(Nama, Alamat, Usia, dan Gender harus sama)\n";
        return;
    }
    
    // Tampilkan kecocokan yang ditemukan
    cout << "\nDitemukan " << matches.size() << " kecocokan:\n";
    cout << string(100, '-') << endl;
    for (size_t i = 0; i < matches.size(); i++) {
        Employee* emp = employees[matches[i].first];
        Pengusaha* peng = pengusaha[matches[i].second];
        
        cout << i + 1 << ". " << emp->getNama() << endl;
        cout << "   Sebagai Employee: " << emp->getPosisi() 
             << " di " << (emp->getTempatKerja() ? emp->getTempatKerja()->getNamaTempat() : "-")
             << " (Gaji: " << (int)emp->getGaji() << ")" << endl;
        cout << "   Sebagai Pengusaha: " << peng->getNamaBisnis() 
             << " (Pendapatan: " << (int)peng->getPendapatan() << ")" << endl;
        cout << string(100, '-') << endl;
    }
    
    cout << "\nPilih nomor untuk dijadikan Owner-Employee (0 untuk batal): ";
    int pilih;
    cin >> pilih;
    cin.ignore();
    
    if (pilih < 1 || pilih > (int)matches.size()) {
        cout << "Dibatalkan.\n";
        return;
    }
    
    Employee* emp = employees[matches[pilih - 1].first];
    Pengusaha* peng = pengusaha[matches[pilih - 1].second];
    
    // Buat OwnerEmployee baru
    OwnerEmployee* oe = new OwnerEmployee();
    
    // Copy data dari Person (ambil dari Employee)
    oe->setNama(emp->getNama());
    oe->setAlamat(emp->getAlamat());
    oe->setUsia(emp->getUsia());
    oe->setGender(emp->getGender());
    
    // Copy data Employee
    oe->Employee::setId(emp->getId());
    oe->setPosisi(emp->getPosisi());
    oe->setEmail(emp->getEmail());
    oe->setGaji(emp->getGaji());
    oe->setTempatKerja(emp->getTempatKerja());
    
    // Copy data Pengusaha
    oe->Pengusaha::setId(peng->getId());
    oe->setNamaBisnis(peng->getNamaBisnis());
    oe->setStartUpDate(peng->getStartUpDate());
    oe->setPendapatan(peng->getPendapatan());
    
    // Input data tambahan khusus OwnerEmployee
    string persentase, statusManajemen;
    cout << "\n--- Data Kepemilikan ---\n";
    cout << "Persentase Kepemilikan (contoh: 50%): "; 
    getline(cin, persentase);
    cout << "Status Manajemen: "; 
    getline(cin, statusManajemen);
    
    ownerEmployees.push_back(oe);
    
    cout << "\n=== Owner-Employee berhasil ditambahkan! ===\n";
    cout << "Nama: " << oe->getNama() << endl;
    cout << "Sebagai Employee di: " << (oe->getTempatKerja() ? oe->getTempatKerja()->getNamaTempat() : "-") << endl;
    cout << "Sebagai Pengusaha: " << oe->getNamaBisnis() << endl;
    cout << "Persentase Kepemilikan: " << persentase << endl;
    cout << "Status Manajemen: " << statusManajemen << endl;
    cout << "Total Kompensasi Tahunan: " << (int)oe->hitungTotalKompensasi() << endl;
}

// ============= MAIN =============
int main() {
    vector<TempatUsaha*> places;
    vector<Employee*> employees;
    vector<Pengusaha*> pengusaha;
    vector<OwnerEmployee*> ownerEmployees;
    
    int pilihan;
    
    do {
        cout << "\n" << string(50, '=') << endl;
        cout << "        SISTEM MANAJEMEN DATA USAHA" << endl;
        cout << string(50, '=') << endl;
        cout << "\n--- INPUT DATA ---\n";
        cout << "1. Tambah Tempat Usaha\n";
        cout << "2. Tambah Employee\n";
        cout << "3. Tambah Pengusaha\n";
        cout << "4. Tambah Owner-Employee\n";
        cout << "\n--- LIHAT DATA ---\n";
        cout << "5. Lihat Data Tempat Usaha\n";
        cout << "6. Lihat Data Employee\n";
        cout << "7. Lihat Data Pengusaha\n";
        cout << "8. Lihat Data Owner-Employee\n";
        cout << "\n0. Keluar\n";
        cout << string(50, '=') << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                inputTempatUsaha(places);
                break;
            case 2:
                if (places.empty()) {
                    cout << "\nPeringatan: Belum ada data tempat usaha!\n";
                    cout << "Tambahkan tempat usaha terlebih dahulu? (y/n): ";
                    char c;
                    cin >> c;
                    cin.ignore();
                    if (c == 'y' || c == 'Y') {
                        inputTempatUsaha(places);
                    }
                }
                inputEmployee(employees, places);
                break;
            case 3:
                if (places.empty()) { // Tambahkan peringatan
                    cout << "\nPeringatan: Belum ada data tempat usaha!\n";
                    cout << "Tambahkan tempat usaha terlebih dahulu? (y/n): ";
                    char c;
                    cin >> c;
                    cin.ignore();
                    if (c == 'y' || c == 'Y') {
                        inputTempatUsaha(places);
                    }
                }
                inputPengusaha(pengusaha, places); // Perubahan di sini
                break;
            case 4:
                inputOwnerEmployee(ownerEmployees, employees, pengusaha);
                break;
            case 5:
                cetakTabelTempat(places);
                break;
            case 6:
                cetakTabelEmployee(employees);
                break;
            case 7:
                cetakTabelPengusaha(pengusaha); // Perubahan di sini
                break;
            case 8:
                cetakTabelOwnerEmployee(ownerEmployees);
                break;
            case 0:
                cout << "\nlalala yeyeye!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
        
    } while (pilihan != 0);
    
    // Cleanup memory
    for (auto p : places) delete p;
    for (auto e : employees) delete e;
    for (auto p : pengusaha) delete p;
    for (auto oe : ownerEmployees) delete oe;
    
    return 0;
}