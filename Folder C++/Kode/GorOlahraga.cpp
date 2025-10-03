#ifndef GOROLAHRAGA_CPP
#define GOROLAHRAGA_CPP

#include "TempatUsaha.cpp"

class GorOlahraga : public TempatUsaha {
private:
    string jenisOlahraga;
    string fasilitas;
    string skala;
    double hargaSewa;

public:
    GorOlahraga() {}
    GorOlahraga(string namaTempat, string noIzin, string kategoriUsaha, string lokasi, string deskripsi,
                string jenisOlahraga, string fasilitas, string skala, double hargaSewa)
        : TempatUsaha(namaTempat, noIzin, kategoriUsaha, lokasi, deskripsi),
          jenisOlahraga(jenisOlahraga), fasilitas(fasilitas), skala(skala), hargaSewa(hargaSewa) {}
};

#endif