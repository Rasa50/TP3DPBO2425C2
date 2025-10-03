#ifndef PERSON_CPP
#define PERSON_CPP

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string nama;
    string alamat;
    int usia;
    string gender;

public:
    Person() {}
    Person(string nama, string alamat, int usia, string gender)
        : nama(nama), alamat(alamat), usia(usia), gender(gender) {}

    void setNama(string nama) { this->nama = nama; }
    string getNama() const { return nama; }

    void setAlamat(string alamat) { this->alamat = alamat; }
    string getAlamat() const { return alamat; }

    void setUsia(int usia) { this->usia = usia; }
    int getUsia() const { return usia; }

    void setGender(string gender) { this->gender = gender; }
    string getGender() const { return gender; }

    Person& operator=(const Person& other) {
        if (this != &other) {
            nama = other.nama;
            alamat = other.alamat;
            usia = other.usia;
            gender = other.gender;
        }
        return *this;
    }
};

#endif