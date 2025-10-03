# GorOlahraga.py
from TempatUsaha import TempatUsaha

class GorOlahraga(TempatUsaha):
    def __init__(self, nama_tempat="", no_izin="", kategori_usaha="", lokasi="", deskripsi="",
                 jenis_olahraga="", fasilitas="", skala="", harga_sewa=0.0):
        super().__init__(nama_tempat, no_izin, kategori_usaha, lokasi, deskripsi)
        self.__jenis_olahraga = jenis_olahraga
        self.__fasilitas = fasilitas
        self.__skala = skala
        self.__harga_sewa = harga_sewa