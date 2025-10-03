# TokoKue.py
from TempatUsaha import TempatUsaha

class TokoKue(TempatUsaha):
    def __init__(self, nama_tempat="", no_izin="", kategori_usaha="", lokasi="", deskripsi="",
                 nama_produk="", jenis="", stok=0):
        super().__init__(nama_tempat, no_izin, kategori_usaha, lokasi, deskripsi)
        self.__nama_produk = nama_produk
        self.__jenis = jenis
        self.__stok = stok