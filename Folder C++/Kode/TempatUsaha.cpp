#ifndef TEMPATUSAHA_CPP
#define TEMPATUSAHA_CPP

#include <string>
using namespace std;

class TempatUsaha {
private:
    string namaTempat;
    string noIzin;
    string kategoriUsaha;
    string lokasi;
    string deskripsi;

public:
    TempatUsaha() {}
    TempatUsaha(string namaTempat, string noIzin, string kategoriUsaha, string lokasi, string deskripsi)
        : namaTempat(namaTempat), noIzin(noIzin), kategoriUsaha(kategoriUsaha), lokasi(lokasi), deskripsi(deskripsi) {}

    void setNamaTempat(string n) { namaTempat = n; }
    string getNamaTempat() const { return namaTempat; }

    void setNoIzin(string n) { noIzin = n; }
    string getNoIzin() const { return noIzin; }

    void setKategoriUsaha(string k) { kategoriUsaha = k; }
    string getKategoriUsaha() const { return kategoriUsaha; }

    void setLokasi(string l) { lokasi = l; }
    string getLokasi() const { return lokasi; }

    void setDeskripsi(string d) { deskripsi = d; }
    string getDeskripsi() const { return deskripsi; }
};

#endif