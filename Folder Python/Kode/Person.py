# Person.py
class Person:
    def __init__(self, nama="", alamat="", usia=0, gender=""):
        self.__nama = nama
        self.__alamat = alamat
        self.__usia = usia
        self.__gender = gender

    def get_nama(self):
        return self.__nama

    def set_nama(self, nama):
        self.__nama = nama

    def get_alamat(self):
        return self.__alamat

    def set_alamat(self, alamat):
        self.__alamat = alamat

    def get_usia(self):
        return self.__usia

    def set_usia(self, usia):
        self.__usia = usia

    def get_gender(self):
        return self.__gender

    def set_gender(self, gender):
        self.__gender = gender