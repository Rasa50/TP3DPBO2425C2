// Main.java
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
    private static List<TempatUsaha> places = new ArrayList<>();
    private static List<Employee> employees = new ArrayList<>();
    private static List<Pengusaha> pengusahaList = new ArrayList<>();
    private static List<OwnerEmployee> ownerEmployees = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    // ============= FUNGSI CETAK =============
    public static void cetakTabelTempat(List<TempatUsaha> places) {
        if (places.isEmpty()) {
            System.out.println("Belum ada data tempat usaha.\n");
            return;
        }
        
        System.out.println("\n" + "=".repeat(100));
        System.out.printf("%-5s %-25s %-12s %-15s %-20s %-30s\n", "No", "Nama Tempat", "No Izin", "Kategori", "Lokasi", "Deskripsi");
        System.out.println("=".repeat(100));
        
        for (int i = 0; i < places.size(); i++) {
            TempatUsaha place = places.get(i);
            System.out.printf("%-5d %-25s %-12s %-15s %-20s %-30s\n", 
                i + 1,
                place.getNamaTempat(),
                place.getNoIzin(),
                place.getKategoriUsaha(),
                place.getLokasi(),
                place.getDeskripsi()
            );
        }
        System.out.println("=".repeat(100) + "\n");
    }

    public static void cetakTabelEmployee(List<Employee> employees) {
        if (employees.isEmpty()) {
            System.out.println("Belum ada data employee.\n");
            return;
        }
        
        System.out.println("\n" + "=".repeat(120));
        System.out.printf("%-5s %-20s %-20s %-6s %-12s %-15s %-25s %-12s %-25s\n", 
            "ID", "Nama", "Alamat", "Usia", "Gender", "Posisi", "Email", "Gaji", "Tempat Kerja");
        System.out.println("=".repeat(120));
        
        for (Employee emp : employees) {
            TempatUsaha tempat = emp.getTempatKerja();
            System.out.printf("%-5d %-20s %-20s %-6d %-12s %-15s %-25s %-12.0f %-25s\n",
                emp.getId(),
                emp.getNama(),
                emp.getAlamat(),
                emp.getUsia(),
                emp.getGender(),
                emp.getPosisi(),
                emp.getEmail(),
                emp.getGaji(),
                (tempat != null ? tempat.getNamaTempat() : "-")
            );
        }
        System.out.println("=".repeat(120) + "\n");
    }

    public static void cetakTabelPengusaha(List<Pengusaha> pengusahaList) {
        if (pengusahaList.isEmpty()) {
            System.out.println("Belum ada data pengusaha.\n");
            return;
        }
        
        System.out.println("\n" + "=".repeat(110));
        System.out.printf("%-5s %-20s %-20s %-6s %-12s %-20s %-15s %-15s\n", 
            "ID", "Nama", "Alamat", "Usia", "Gender", "Nama Bisnis", "Tanggal Mulai", "Pendapatan");
        System.out.println("=".repeat(110));
        
        for (Pengusaha p : pengusahaList) {
            System.out.printf("%-5d %-20s %-20s %-6d %-12s %-20s %-15s %-15.0f\n",
                p.getId(),
                p.getNama(),
                p.getAlamat(),
                p.getUsia(),
                p.getGender(),
                p.getNamaBisnis(),
                p.getStartUpDate(),
                p.getPendapatan()
            );
        }
        System.out.println("=".repeat(110) + "\n");
    }

    public static void cetakTabelOwnerEmployee(List<OwnerEmployee> ownerEmployees) {
        if (ownerEmployees.isEmpty()) {
            System.out.println("Belum ada data owner-employee.\n");
            return;
        }
        
        System.out.println("\n" + "=".repeat(140));
        System.out.printf("%-5s %-18s %-10s %-15s %-12s %-20s %-15s %-15s %-20s\n",
            "ID", "Nama", "Usia", "Posisi", "Gaji", "Nama Bisnis", "Pendapatan", "% Kepemilikan", "Status Manajemen");
        System.out.println("=".repeat(140));
        
        for (OwnerEmployee oe : ownerEmployees) {
            System.out.printf("%-5d %-18s %-10d %-15s %-12.0f %-20s %-15.0f %-15s %-20s\n",
                oe.getIdOE(),
                oe.getNama(),
                oe.getUsia(),
                oe.getPosisi(),
                oe.getGaji(),
                oe.getNamaBisnis(),
                oe.getPendapatan(),
                oe.getPersentaseKepemilikan(),
                oe.getStatusManajemen()
            );
        }
        System.out.println("=".repeat(140) + "\n");
    }

    // ============= FUNGSI INPUT =============
    public static void inputTempatUsaha() {
        System.out.println("\n=== TAMBAH TEMPAT USAHA ===\n");
        System.out.println("Pilih Jenis:");
        System.out.println("1. Tempat Usaha Umum");
        System.out.println("2. Toko Kue");
        System.out.println("3. Aula");
        System.out.println("4. GOR Olahraga");
        System.out.print("Pilihan: ");
        
        int jenis;
        try {
            jenis = scanner.nextInt();
            scanner.nextLine();
        } catch (InputMismatchException e) {
            System.out.println("\nPilihan tidak valid! Masukkan angka.");
            scanner.nextLine();
            return;
        }
        
        String nama, noIzin, kategori, lokasi, deskripsi;
        
        System.out.print("Nama Tempat: "); nama = scanner.nextLine();
        System.out.print("No Izin: "); noIzin = scanner.nextLine();
        System.out.print("Kategori Usaha: "); kategori = scanner.nextLine();
        System.out.print("Lokasi: "); lokasi = scanner.nextLine();
        System.out.print("Deskripsi: "); deskripsi = scanner.nextLine();
        
        if (jenis == 1) {
            places.add(new TempatUsaha(nama, noIzin, kategori, lokasi, deskripsi));
        } else if (jenis == 2) {
            System.out.print("Nama Produk: "); String namaProduk = scanner.nextLine();
            System.out.print("Jenis Kue: "); String jenisKue = scanner.nextLine();
            System.out.print("Stok: "); int stok = scanner.nextInt(); scanner.nextLine();
            places.add(new TokoKue(nama, noIzin, kategori, lokasi, deskripsi, namaProduk, jenisKue, stok));
        } else if (jenis == 3) {
            System.out.print("Luas (m2): "); double luas = scanner.nextDouble(); scanner.nextLine();
            System.out.print("Kapasitas: "); String kapasitas = scanner.nextLine();
            System.out.print("Fasilitas: "); String fasilitas = scanner.nextLine();
            System.out.print("Harga Sewa: "); double hargaSewa = scanner.nextDouble(); scanner.nextLine();
            System.out.print("Tipe: "); String tipe = scanner.nextLine();
            places.add(new Aula(nama, noIzin, kategori, lokasi, deskripsi, luas, kapasitas, fasilitas, hargaSewa, tipe));
        } else if (jenis == 4) {
            System.out.print("Jenis Olahraga: "); String jenisOlahraga = scanner.nextLine();
            System.out.print("Fasilitas: "); String fasilitas = scanner.nextLine();
            System.out.print("Skala: "); String skala = scanner.nextLine();
            System.out.print("Harga Sewa: "); double hargaSewa = scanner.nextDouble(); scanner.nextLine();
            places.add(new GorOlahraga(nama, noIzin, kategori, lokasi, deskripsi, jenisOlahraga, fasilitas, skala, hargaSewa));
        }
        
        System.out.println("Tempat usaha berhasil ditambahkan!\n");
    }

    public static void inputEmployee() {
        System.out.println("\n=== TAMBAH EMPLOYEE ===\n");
        
        int id, usia;
        String nama, alamat, gender, posisi, email;
        double gaji;
        
        try {
            System.out.print("ID: "); id = scanner.nextInt(); scanner.nextLine();
            System.out.print("Nama: "); nama = scanner.nextLine();
            System.out.print("Alamat: "); alamat = scanner.nextLine();
            System.out.print("Usia: "); usia = scanner.nextInt(); scanner.nextLine();
            System.out.print("Gender: "); gender = scanner.nextLine();
            System.out.print("Posisi: "); posisi = scanner.nextLine();
            System.out.print("Email: "); email = scanner.nextLine();
            System.out.print("Gaji: "); gaji = scanner.nextDouble(); scanner.nextLine();
        } catch (InputMismatchException e) {
            System.out.println("\nInput tidak valid! Pastikan ID, Usia, dan Gaji adalah angka.");
            scanner.nextLine();
            return;
        }

        TempatUsaha tempatKerja = null;
        if (!places.isEmpty()) {
            System.out.println("\nPilih Tempat Kerja:");
            for (int i = 0; i < places.size(); i++) {
                System.out.println((i + 1) + ". " + places.get(i).getNamaTempat() + " (" + places.get(i).getKategoriUsaha() + ")");
            }
            System.out.println("0. Tidak ada");
            System.out.print("Pilihan: ");
            int pilih = scanner.nextInt();
            scanner.nextLine();
            
            if (pilih > 0 && pilih <= places.size()) {
                tempatKerja = places.get(pilih - 1);
            }
        }
        
        employees.add(new Employee(nama, alamat, usia, gender, id, posisi, email, gaji, tempatKerja));
        System.out.println("Employee berhasil ditambahkan!\n");
    }

    public static void inputPengusaha() {
        System.out.println("\n=== TAMBAH PENGUSAHA ===\n");
        
        int id, usia;
        String nama, alamat, gender, namaBisnis, startUpDate;
        double pendapatan;
        
        try {
            System.out.print("ID: "); id = scanner.nextInt(); scanner.nextLine();
            System.out.print("Nama: "); nama = scanner.nextLine();
            System.out.print("Alamat: "); alamat = scanner.nextLine();
            System.out.print("Usia: "); usia = scanner.nextInt(); scanner.nextLine();
            System.out.print("Gender: "); gender = scanner.nextLine();
            System.out.print("Nama Bisnis: "); namaBisnis = scanner.nextLine();
            System.out.print("Tanggal Mulai (dd-mm-yyyy): "); startUpDate = scanner.nextLine();
            System.out.print("Pendapatan: "); pendapatan = scanner.nextDouble(); scanner.nextLine();
        } catch (InputMismatchException e) {
            System.out.println("\nInput tidak valid! Pastikan ID, Usia, dan Pendapatan adalah angka.");
            scanner.nextLine();
            return;
        }

        pengusahaList.add(new Pengusaha(nama, alamat, usia, gender, id, namaBisnis, startUpDate, pendapatan));
        System.out.println("Pengusaha berhasil ditambahkan!\n");
    }

    public static void inputOwnerEmployee() {
        System.out.println("\n=== TAMBAH OWNER-EMPLOYEE ===\n");
        
        if (employees.isEmpty() || pengusahaList.isEmpty()) {
            System.out.println("Error: Harus ada data Employee dan Pengusaha terlebih dahulu!\n");
            return;
        }
        
        System.out.println("\n--- Mencari Kecocokan Data ---\n");
        List<Integer> employeeMatches = new ArrayList<>();
        List<Integer> pengusahaMatches = new ArrayList<>();
        
        for (int i = 0; i < employees.size(); i++) {
            for (int j = 0; j < pengusahaList.size(); j++) {
                if (employees.get(i).getNama().equals(pengusahaList.get(j).getNama()) &&
                    employees.get(i).getAlamat().equals(pengusahaList.get(j).getAlamat()) &&
                    employees.get(i).getUsia() == pengusahaList.get(j).getUsia() &&
                    employees.get(i).getGender().equals(pengusahaList.get(j).getGender())) {
                    employeeMatches.add(i);
                    pengusahaMatches.add(j);
                }
            }
        }
        
        if (employeeMatches.isEmpty()) {
            System.out.println("Tidak ada data yang cocok antara Employee dan Pengusaha!\n");
            return;
        }
        
        System.out.println("\nDitemukan " + employeeMatches.size() + " kecocokan:\n");
        System.out.println("-".repeat(100));
        for (int i = 0; i < employeeMatches.size(); i++) {
            Employee emp = employees.get(employeeMatches.get(i));
            Pengusaha peng = pengusahaList.get(pengusahaMatches.get(i));
            
            System.out.println((i + 1) + ". " + emp.getNama());
            System.out.println("   Sebagai Employee: " + emp.getPosisi() + " di " + (emp.getTempatKerja() != null ? emp.getTempatKerja().getNamaTempat() : "-") + " (Gaji: " + (int)emp.getGaji() + ")");
            System.out.println("   Sebagai Pengusaha: " + peng.getNamaBisnis() + " (Pendapatan: " + (int)peng.getPendapatan() + ")");
            System.out.println("-".repeat(100));
        }
        
        System.out.print("\nPilih nomor untuk dijadikan Owner-Employee (0 untuk batal): ");
        int pilih = scanner.nextInt();
        scanner.nextLine();
        
        if (pilih < 1 || pilih > employeeMatches.size()) {
            System.out.println("Dibatalkan.\n");
            return;
        }
        
        Employee emp = employees.get(employeeMatches.get(pilih - 1));
        Pengusaha peng = pengusahaList.get(pengusahaMatches.get(pilih - 1));
        
        System.out.println("\n--- Data Kepemilikan ---\n");
        System.out.print("Persentase Kepemilikan (contoh: 50%): "); 
        String persentase = scanner.nextLine();
        System.out.print("Status Manajemen: "); 
        String statusManajemen = scanner.nextLine();
        
        OwnerEmployee oe = new OwnerEmployee(
            emp.getNama(), emp.getAlamat(), emp.getUsia(), emp.getGender(),
            emp.getId(), emp.getPosisi(), emp.getEmail(), emp.getGaji(),
            peng.getId(), peng.getNamaBisnis(), peng.getStartUpDate(), peng.getPendapatan(),
            ownerEmployees.size() + 1, persentase, statusManajemen);
        oe.setTempatKerja(emp.getTempatKerja()); // Assign tempat kerja
        
        ownerEmployees.add(oe);
        
        System.out.println("\n=== Owner-Employee berhasil ditambahkan! ===\n");
        System.out.println("Nama: " + oe.getNama());
        System.out.println("Sebagai Employee di: " + (oe.getTempatKerja() != null ? oe.getTempatKerja().getNamaTempat() : "-"));
        System.out.println("Sebagai Pengusaha: " + oe.getNamaBisnis());
        System.out.println("Persentase Kepemilikan: " + persentase);
        System.out.println("Status Manajemen: " + statusManajemen);
        System.out.println("Total Kompensasi Tahunan: " + (int)oe.hitungTotalKompensasi());
    }
    
    public static void main(String[] args) {
        int pilihan;
        do {
            System.out.println("\n" + "=".repeat(50));
            System.out.println("        SISTEM MANAJEMEN DATA USAHA");
            System.out.println("=".repeat(50));
            System.out.println("\n--- INPUT DATA ---");
            System.out.println("1. Tambah Tempat Usaha");
            System.out.println("2. Tambah Employee");
            System.out.println("3. Tambah Pengusaha");
            System.out.println("4. Tambah Owner-Employee");
            System.out.println("\n--- LIHAT DATA ---");
            System.out.println("5. Lihat Data Tempat Usaha");
            System.out.println("6. Lihat Data Employee");
            System.out.println("7. Lihat Data Pengusaha");
            System.out.println("8. Lihat Data Owner-Employee");
            System.out.println("\n0. Keluar");
            System.out.println("=".repeat(50));
            System.out.print("Pilih: ");
            
            try {
                pilihan = scanner.nextInt();
                scanner.nextLine();
            } catch (InputMismatchException e) {
                System.out.println("\nPilihan tidak valid! Masukkan angka.");
                scanner.nextLine();
                pilihan = -1;
                continue;
            }

            switch(pilihan) {
                case 1:
                    inputTempatUsaha();
                    break;
                case 2:
                    if (places.isEmpty()) {
                        System.out.println("\nPeringatan: Belum ada data tempat usaha!");
                        System.out.print("Tambahkan tempat usaha terlebih dahulu? (y/n): ");
                        String c = scanner.nextLine();
                        if (c.equalsIgnoreCase("y")) {
                            inputTempatUsaha();
                            if(places.isEmpty()) break; // Jika dibatalkan
                        } else {
                            break;
                        }
                    }
                    inputEmployee();
                    break;
                case 3:
                    inputPengusaha();
                    break;
                case 4:
                    inputOwnerEmployee();
                    break;
                case 5:
                    cetakTabelTempat(places);
                    break;
                case 6:
                    cetakTabelEmployee(employees);
                    break;
                case 7:
                    cetakTabelPengusaha(pengusahaList);
                    break;
                case 8:
                    cetakTabelOwnerEmployee(ownerEmployees);
                    break;
                case 0:
                    System.out.println("\nlalala yeyeye!");
                    break;
                default:
                    System.out.println("\nPilihan tidak valid!");
            }
        } while (pilihan != 0);
        
        scanner.close();
    }
}