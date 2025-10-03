# Aula.py
from TempatUsaha import TempatUsaha

class Aula(TempatUsaha):
    def __init__(self, nama_tempat="", no_izin="", kategori_usaha="", lokasi="", deskripsi="",
                 luas=0.0, kapasitas="", fasilitas="", harga_sewa=0.0, tipe=""):
        super().__init__(nama_tempat, no_izin, kategori_usaha, lokasi, deskripsi)
        self.__luas = luas
        self.__kapasitas = kapasitas
        self.__fasilitas = fasilitas
        self.__harga_sewa = harga_sewa
        self.__tipe = tipe