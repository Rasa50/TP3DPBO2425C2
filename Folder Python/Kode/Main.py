# Main.py
from Person import Person
from TempatUsaha import TempatUsaha
from Employee import Employee
from Pengusaha import Pengusaha
from OwnerEmployee import OwnerEmployee
from Aula import Aula
from GorOlahraga import GorOlahraga
from TokoKue import TokoKue

import os

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

# ============= FUNGSI CETAK =============
def cetak_tabel_tempat(places):
    if not places:
        print("Belum ada data tempat usaha.\n")
        return
    
    print("\n" + "=" * 100)
    print(f"{'No':<5} {'Nama Tempat':<25} {'No Izin':<12} {'Kategori':<15} {'Lokasi':<20} {'Deskripsi':<30}")
    print("=" * 100)
    
    for i, place in enumerate(places, 1):
        print(f"{i:<5} {place.get_nama_tempat():<25} {place.get_no_izin():<12} {place.get_kategori_usaha():<15} {place.get_lokasi():<20} {place.get_deskripsi():<30}")
    print("=" * 100)

def cetak_tabel_employee(employees):
    if not employees:
        print("Belum ada data employee.\n")
        return
    
    print("\n" + "=" * 120)
    print(f"{'ID':<5} {'Nama':<20} {'Alamat':<20} {'Usia':<6} {'Gender':<12} {'Posisi':<15} {'Email':<25} {'Gaji':<12} {'Tempat Kerja':<25}")
    print("=" * 120)
    
    for emp in employees:
        tempat_kerja = emp.get_tempat_kerja()
        tempat_nama = tempat_kerja.get_nama_tempat() if tempat_kerja else "-"
        print(f"{emp.get_id():<5} {emp.get_nama():<20} {emp.get_alamat():<20} {emp.get_usia():<6} {emp.get_gender():<12} {emp.get_posisi():<15} {emp.get_email():<25} {int(emp.get_gaji()):<12} {tempat_nama:<25}")
    print("=" * 120)

def cetak_tabel_pengusaha(pengusaha):
    if not pengusaha:
        print("Belum ada data pengusaha.\n")
        return
    
    print("\n" + "=" * 110)
    print(f"{'ID':<5} {'Nama':<20} {'Alamat':<20} {'Usia':<6} {'Gender':<12} {'Nama Bisnis':<20} {'Tanggal Mulai':<15} {'Pendapatan':<15}")
    print("=" * 110)
    
    for p in pengusaha:
        print(f"{p.get_id():<5} {p.get_nama():<20} {p.get_alamat():<20} {p.get_usia():<6} {p.get_gender():<12} {p.get_nama_bisnis():<20} {p.get_startup_date():<15} {int(p.get_pendapatan()):<15}")
    print("=" * 110)

def cetak_tabel_owner_employee(owner_employees):
    if not owner_employees:
        print("Belum ada data owner-employee.\n")
        return
    
    print("\n" + "=" * 140)
    print(f"{'ID':<5} {'Nama':<18} {'Usia':<10} {'Posisi':<15} {'Gaji':<12} {'Nama Bisnis':<20} {'Pendapatan':<15} {'% Kepemilikan':<15} {'Status Manajemen':<20}")
    print("=" * 140)
    
    for oe in owner_employees:
        print(f"{oe.get_id_oe():<5} {oe.get_nama():<18} {oe.get_usia():<10} {oe.get_posisi():<15} {int(oe.get_gaji()):<12} {oe.get_nama_bisnis():<20} {int(oe.getPendapatan()):<15} {oe.get_persentase_kepemilikan():<15} {oe.get_status_manajemen():<20}")
    print("=" * 140)

# ============= FUNGSI INPUT =============
def input_tempat_usaha(places):
    print("\n=== TAMBAH TEMPAT USAHA ===\n")
    print("Pilih Jenis:")
    print("1. Tempat Usaha Umum")
    print("2. Toko Kue")
    print("3. Aula")
    print("4. GOR Olahraga")
    try:
        jenis = int(input("Pilihan: "))
    except ValueError:
        print("\nPilihan tidak valid! Masukkan angka.")
        return
    
    nama = input("Nama Tempat: ")
    no_izin = input("No Izin: ")
    kategori = input("Kategori Usaha: ")
    lokasi = input("Lokasi: ")
    deskripsi = input("Deskripsi: ")
    
    if jenis == 1:
        places.append(TempatUsaha(nama, no_izin, kategori, lokasi, deskripsi))
    elif jenis == 2:
        nama_produk = input("Nama Produk: ")
        jenis_kue = input("Jenis Kue: ")
        try:
            stok = int(input("Stok: "))
            places.append(TokoKue(nama, no_izin, kategori, lokasi, deskripsi, nama_produk, jenis_kue, stok))
        except ValueError:
            print("Stok harus berupa angka.")
            return
    elif jenis == 3:
        try:
            luas = float(input("Luas (m2): "))
            kapasitas = input("Kapasitas: ")
            fasilitas = input("Fasilitas: ")
            harga_sewa = float(input("Harga Sewa: "))
            tipe = input("Tipe: ")
            places.append(Aula(nama, no_izin, kategori, lokasi, deskripsi, luas, kapasitas, fasilitas, harga_sewa, tipe))
        except ValueError:
            print("Input luas atau harga sewa tidak valid.")
            return
    elif jenis == 4:
        try:
            jenis_olahraga = input("Jenis Olahraga: ")
            fasilitas = input("Fasilitas: ")
            skala = input("Skala: ")
            harga_sewa = float(input("Harga Sewa: "))
            places.append(GorOlahraga(nama, no_izin, kategori, lokasi, deskripsi, jenis_olahraga, fasilitas, skala, harga_sewa))
        except ValueError:
            print("Input harga sewa tidak valid.")
            return
    else:
        print("Pilihan tidak valid.")
        return
    
    print("Tempat usaha berhasil ditambahkan!\n")

def input_employee(employees, places):
    print("\n=== TAMBAH EMPLOYEE ===\n")
    
    try:
        id = int(input("ID: "))
        nama = input("Nama: ")
        alamat = input("Alamat: ")
        usia = int(input("Usia: "))
        gender = input("Gender: ")
        posisi = input("Posisi: ")
        email = input("Email: ")
        gaji = float(input("Gaji: "))
    except ValueError:
        print("\nInput tidak valid! Pastikan ID, Usia, dan Gaji adalah angka.")
        return
    
    tempat_kerja = None
    if places:
        print("\nPilih Tempat Kerja:")
        for i, place in enumerate(places, 1):
            print(f"{i}. {place.get_nama_tempat()} ({place.get_kategori_usaha()})")
        print("0. Tidak ada")
        try:
            pilih = int(input("Pilihan: "))
            if 0 < pilih <= len(places):
                tempat_kerja = places[pilih - 1]
        except ValueError:
            print("Pilihan tidak valid.")

    employees.append(Employee(nama, alamat, usia, gender, id, posisi, email, gaji, tempat_kerja))
    print("Employee berhasil ditambahkan!\n")

def input_pengusaha(pengusaha_list):
    print("\n=== TAMBAH PENGUSAHA ===\n")
    
    try:
        id = int(input("ID: "))
        nama = input("Nama: ")
        alamat = input("Alamat: ")
        usia = int(input("Usia: "))
        gender = input("Gender: ")
        nama_bisnis = input("Nama Bisnis: ")
        startup_date = input("Tanggal Mulai (dd-mm-yyyy): ")
        pendapatan = float(input("Pendapatan: "))
    except ValueError:
        print("\nInput tidak valid! Pastikan ID, Usia, dan Pendapatan adalah angka.")
        return

    pengusaha_list.append(Pengusaha(nama, alamat, usia, gender, id, nama_bisnis, startup_date, pendapatan))
    print("Pengusaha berhasil ditambahkan!\n")

def input_owner_employee(owner_employees, employees, pengusaha_list):
    print("\n=== TAMBAH OWNER-EMPLOYEE ===\n")
    
    if not employees or not pengusaha_list:
        print("Error: Harus ada data Employee dan Pengusaha terlebih dahulu!\n")
        return
    
    print("\n--- Mencari Kecocokan Data ---\n")
    matches = []
    
    for i, emp in enumerate(employees):
        for j, peng in enumerate(pengusaha_list):
            if (emp.get_nama() == peng.get_nama() and
                emp.get_alamat() == peng.get_alamat() and
                emp.get_usia() == peng.get_usia() and
                emp.get_gender() == peng.get_gender()):
                matches.append({'emp_idx': i, 'peng_idx': j})
    
    if not matches:
        print("Tidak ada data yang cocok antara Employee dan Pengusaha!\n")
        return
    
    print(f"\nDitemukan {len(matches)} kecocokan:")
    print("-" * 100)
    for i, match in enumerate(matches, 1):
        emp = employees[match['emp_idx']]
        peng = pengusaha_list[match['peng_idx']]
        print(f"{i}. {emp.get_nama()}")
        print(f"   Sebagai Employee: {emp.get_posisi()} di {(emp.get_tempat_kerja().get_nama_tempat() if emp.get_tempat_kerja() else '-')}")
        print(f"   Sebagai Pengusaha: {peng.get_nama_bisnis()} (Pendapatan: {int(peng.get_pendapatan())})")
        print("-" * 100)
    
    try:
        pilih = int(input("\nPilih nomor untuk dijadikan Owner-Employee (0 untuk batal): "))
        if pilih < 1 or pilih > len(matches):
            print("Dibatalkan.")
            return
    except ValueError:
        print("Pilihan tidak valid.")
        return

    emp = employees[matches[pilih - 1]['emp_idx']]
    peng = pengusaha_list[matches[pilih - 1]['peng_idx']]
    
    print("\n--- Data Kepemilikan ---\n")
    persentase = input("Persentase Kepemilikan (contoh: 50%): ")
    status_manajemen = input("Status Manajemen: ")
    
    oe = OwnerEmployee(
        emp.get_nama(), emp.get_alamat(), emp.get_usia(), emp.get_gender(),
        emp.get_id(), emp.get_posisi(), emp.get_email(), emp.get_gaji(),
        peng.get_id(), peng.get_nama_bisnis(), peng.get_startup_date(), peng.get_pendapatan(),
        len(owner_employees) + 1, persentase, status_manajemen
    )
    oe.set_tempat_kerja(emp.get_tempat_kerja())
    
    owner_employees.append(oe)
    
    print("\n=== Owner-Employee berhasil ditambahkan! ===")
    print(f"Nama: {oe.get_nama()}")
    print(f"Sebagai Employee di: {(oe.get_tempat_kerja().get_nama_tempat() if oe.get_tempat_kerja() else '-')}")
    print(f"Sebagai Pengusaha: {oe.get_nama_bisnis()}")
    print(f"Persentase Kepemilikan: {persentase}")
    print(f"Status Manajemen: {status_manajemen}")
    print(f"Total Kompensasi Tahunan: {int(oe.hitung_total_kompensasi())}")

# ============= MAIN LOOP =============
def main():
    places = []
    employees = []
    pengusaha_list = []
    owner_employees = []
    
    while True:
        print("\n" + "=" * 50)
        print("        SISTEM MANAJEMEN DATA USAHA")
        print("=" * 50)
        print("\n--- INPUT DATA ---")
        print("1. Tambah Tempat Usaha")
        print("2. Tambah Employee")
        print("3. Tambah Pengusaha")
        print("4. Tambah Owner-Employee")
        print("\n--- LIHAT DATA ---")
        print("5. Lihat Data Tempat Usaha")
        print("6. Lihat Data Employee")
        print("7. Lihat Data Pengusaha")
        print("8. Lihat Data Owner-Employee")
        print("\n0. Keluar")
        print("=" * 50)
        
        pilihan = input("Pilih: ")
        
        if pilihan == '1':
            input_tempat_usaha(places)
        elif pilihan == '2':
            if not places:
                print("\nPeringatan: Belum ada data tempat usaha!")
                konfirmasi = input("Tambahkan tempat usaha terlebih dahulu? (y/n): ")
                if konfirmasi.lower() == 'y':
                    input_tempat_usaha(places)
                    if not places:
                        continue
            input_employee(employees, places)
        elif pilihan == '3':
            input_pengusaha(pengusaha_list)
        elif pilihan == '4':
            input_owner_employee(owner_employees, employees, pengusaha_list)
        elif pilihan == '5':
            cetak_tabel_tempat(places)
        elif pilihan == '6':
            cetak_tabel_employee(employees)
        elif pilihan == '7':
            cetak_tabel_pengusaha(pengusaha_list)
        elif pilihan == '8':
            cetak_tabel_owner_employee(owner_employees)
        elif pilihan == '0':
            print("\nlalala yeyeye!")
            break
        else:
            print("\nPilihan tidak valid!\n")

if __name__ == "__main__":
    main()