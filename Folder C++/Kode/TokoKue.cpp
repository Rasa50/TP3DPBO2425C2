#ifndef TOKOKUE_CPP
#define TOKOKUE_CPP

#include "TempatUsaha.cpp"

class TokoKue : public TempatUsaha {
private:
    string namaProduk;
    string jenis;
    int stok;

public:
    TokoKue() {}
    TokoKue(string namaTempat, string noIzin, string kategoriUsaha, string lokasi, string deskripsi,
            string namaProduk, string jenis, int stok)
        : TempatUsaha(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi),
          namaProduk(namaProduk), jenis(jenis), stok(stok) {}
};

#endif