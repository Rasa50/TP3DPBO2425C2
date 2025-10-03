#ifndef AULA_CPP
#define AULA_CPP

#include "TempatUsaha.cpp"

class Aula : public TempatUsaha {
private:
    double luas;
    string kapasitas;
    string fasilitas;
    double hargaSewa;
    string tipe;

public:
    Aula() {}
    Aula(string namaTempat, string noIzin, string kategoriUsaha, string lokasi, string deskripsi,
         double luas, string kapasitas, string fasilitas, double hargaSewa, string tipe)
        : TempatUsaha(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi),
          luas(luas), kapasitas(kapasitas), fasilitas(fasilitas), hargaSewa(hargaSewa), tipe(tipe) {}
};

#endif