# Pengusaha.py
from Person import Person

class Pengusaha(Person):
    def __init__(self, nama="", alamat="", usia=0, gender="", id=0, nama_bisnis="", startup_date="", pendapatan=0.0):
        super().__init__(nama, alamat, usia, gender)
        self.__id = id
        self.__nama_bisnis = nama_bisnis
        self.__startup_date = startup_date
        self.__pendapatan = pendapatan
    
    def get_id(self):
        return self.__id
        
    def set_id(self, id):
        self.__id = id

    def get_nama_bisnis(self):
        return self.__nama_bisnis

    def set_nama_bisnis(self, nama_bisnis):
        self.__nama_bisnis = nama_bisnis

    def get_startup_date(self):
        return self.__startup_date

    def set_startup_date(self, startup_date):
        self.__startup_date = startup_date

    def get_pendapatan(self):
        return self.__pendapatan

    def set_pendapatan(self, pendapatan):
        self.__pendapatan = pendapatan
    
    def hitung_profit(self):
        return self.__pendapatan * 0.3