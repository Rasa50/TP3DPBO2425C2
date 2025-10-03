#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

#include "Person.cpp"
#include "TempatUsaha.cpp"

class Employee : virtual public Person {
private:
    int id;
    string posisi;
    string email;
    double gaji;
    TempatUsaha* tempatKerja; // hubungan ke tempat kerja

public:
    Employee() {}
    Employee(string nama, string alamat, int usia, string gender, int id, string posisi, string email, double gaji, TempatUsaha* tempatKerja = nullptr)
        : Person(nama, alamat, usia, gender), id(id), posisi(posisi), email(email), gaji(gaji), tempatKerja(tempatKerja) {}

    void setId(int id) { this->id = id; }
    int getId() const { return id; }

    void setPosisi(string posisi) { this->posisi = posisi; }
    string getPosisi() const { return posisi; }

    void setEmail(string email) { this->email = email; }
    string getEmail() const { return email; }

    void setGaji(double gaji) { this->gaji = gaji; }
    double getGaji() const { return gaji; }

    double hitungGajiTahunan() const { return gaji * 12; }

    void setTempatKerja(TempatUsaha* t) { tempatKerja = t; }
    TempatUsaha* getTempatKerja() const { return tempatKerja; }

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Person::operator=(other);
            id = other.id;
            posisi = other.posisi;
            email = other.email;
            gaji = other.gaji;
        }
        return *this;
    }
};

#endif