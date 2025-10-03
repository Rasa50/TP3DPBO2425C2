#ifndef PENGUSAHA_H
#define PENGUSAHA_H

#include "Person.cpp"
#include "TempatUsaha.cpp"

class Pengusaha : virtual public Person {
private:
    int id;
    string namaBisnis;
    string startUpDate;
    double pendapatan;
    TempatUsaha* tempatUsahaDimiliki;

public:
    Pengusaha() : tempatUsahaDimiliki(nullptr) {}
    Pengusaha(string nama, string alamat, int usia, string gender,
              int id, string namaBisnis, string startUpDate, double pendapatan,
              TempatUsaha* tempatUsahaDimiliki = nullptr)
        : Person(nama, alamat, usia, gender), id(id), namaBisnis(namaBisnis),
          startUpDate(startUpDate), pendapatan(pendapatan), tempatUsahaDimiliki(tempatUsahaDimiliki) {}

    void setId(int id) { this->id = id; }
    int getId() const { return id; }

    void setNamaBisnis(string namaBisnis) { this->namaBisnis = namaBisnis; }
    string getNamaBisnis() const { return namaBisnis; }

    void setStartUpDate(string startUpDate) { this->startUpDate = startUpDate; }
    string getStartUpDate() const { return startUpDate; }

    void setPendapatan(double pendapatan) { this->pendapatan = pendapatan; }
    double getPendapatan() const { return pendapatan; }

    double hitungProfit() const { return pendapatan * 0.3; }

    void setTempatUsahaDimiliki(TempatUsaha* t) { tempatUsahaDimiliki = t; }
    TempatUsaha* getTempatUsahaDimiliki() const { return tempatUsahaDimiliki; }

    Pengusaha& operator=(const Pengusaha& other) {
        if (this != &other) {
            Person::operator=(other);
            id = other.id;
            namaBisnis = other.namaBisnis;
            startUpDate = other.startUpDate;
            pendapatan = other.pendapatan;
            tempatUsahaDimiliki = other.tempatUsahaDimiliki;
        }
        return *this;
    }
};

#endif