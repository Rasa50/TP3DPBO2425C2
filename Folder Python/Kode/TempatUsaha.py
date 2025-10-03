# TempatUsaha.py
class TempatUsaha:
    def __init__(self, nama_tempat="", no_izin="", kategori_usaha="", lokasi="", deskripsi=""):
        self.__nama_tempat = nama_tempat
        self.__no_izin = no_izin
        self.__kategori_usaha = kategori_usaha
        self.__lokasi = lokasi
        self.__deskripsi = deskripsi

    def get_nama_tempat(self):
        return self.__nama_tempat

    def set_nama_tempat(self, nama_tempat):
        self.__nama_tempat = nama_tempat

    def get_no_izin(self):
        return self.__no_izin

    def set_no_izin(self, no_izin):
        self.__no_izin = no_izin

    def get_kategori_usaha(self):
        return self.__kategori_usaha

    def set_kategori_usaha(self, kategori_usaha):
        self.__kategori_usaha = kategori_usaha

    def get_lokasi(self):
        return self.__lokasi

    def set_lokasi(self, lokasi):
        self.__lokasi = lokasi

    def get_deskripsi(self):
        return self.__deskripsi

    def set_deskripsi(self, deskripsi):
        self.__deskripsi = deskripsi