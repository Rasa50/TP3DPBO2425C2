# OwnerEmployee.py
from Employee import Employee
from Pengusaha import Pengusaha
# Perhatikan bahwa multiple inheritance digunakan di sini.
# Person.__init__ dipanggil secara eksplisit untuk menghindari duplikasi inisialisasi.

class OwnerEmployee(Employee, Pengusaha):
    def __init__(self, nama="", alamat="", usia=0, gender="",
                 id_e=0, posisi="", email="", gaji=0.0,
                 id_p=0, nama_bisnis="", startup_date="", pendapatan=0.0,
                 id_oe=0, persentase_kepemilikan="", status_manajemen=""):
        
        # Inisialisasi superclass Person secara eksplisit untuk mengatasi Diamond Problem
        Person.__init__(self, nama, alamat, usia, gender)
        # Inisialisasi Employee dan Pengusaha
        Employee.__init__(self, nama, alamat, usia, gender, id_e, posisi, email, gaji)
        Pengusaha.__init__(self, nama, alamat, usia, gender, id_p, nama_bisnis, startup_date, pendapatan)

        self.__id_oe = id_oe
        self.__persentase_kepemilikan = persentase_kepemilikan
        self.__status_manajemen = status_manajemen

    def get_id_oe(self):
        return self.__id_oe

    def set_id_oe(self, id_oe):
        self.__id_oe = id_oe
    
    def get_persentase_kepemilikan(self):
        return self.__persentase_kepemilikan

    def set_persentase_kepemilikan(self, persentase_kepemilikan):
        self.__persentase_kepemilikan = persentase_kepemilikan

    def get_status_manajemen(self):
        return self.__status_manajemen

    def set_status_manajemen(self, status_manajemen):
        self.__status_manajemen = status_manajemen
    
    def hitung_total_kompensasi(self):
        return self.hitung_gaji_tahunan() + (self.hitung_profit() * 0.5)