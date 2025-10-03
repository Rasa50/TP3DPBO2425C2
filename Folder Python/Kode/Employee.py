# Employee.py
from Person import Person
from TempatUsaha import TempatUsaha

class Employee(Person):
    def __init__(self, nama="", alamat="", usia=0, gender="", id=0, posisi="", email="", gaji=0.0, tempat_kerja=None):
        super().__init__(nama, alamat, usia, gender)
        self.__id = id
        self.__posisi = posisi
        self.__email = email
        self.__gaji = gaji
        self.__tempat_kerja = tempat_kerja

    def get_id(self):
        return self.__id

    def set_id(self, id):
        self.__id = id

    def get_posisi(self):
        return self.__posisi

    def set_posisi(self, posisi):
        self.__posisi = posisi

    def get_email(self):
        return self.__email

    def set_email(self, email):
        self.__email = email

    def get_gaji(self):
        return self.__gaji

    def set_gaji(self, gaji):
        self.__gaji = gaji
    
    def hitung_gaji_tahunan(self):
        return self.__gaji * 12

    def get_tempat_kerja(self):
        return self.__tempat_kerja

    def set_tempat_kerja(self, tempat_kerja):
        self.__tempat_kerja = tempat_kerja