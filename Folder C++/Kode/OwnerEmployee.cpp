#ifndef OWNEREMPLOYEE_CPP
#define OWNEREMPLOYEE_CPP

#include "Employee.cpp"
#include "Pengusaha.cpp"

class OwnerEmployee : public Employee, public Pengusaha {
private:
    int idOE;
    string persentaseKepemilikan;
    string statusManajemen;

public:
    OwnerEmployee() : idOE(0), persentaseKepemilikan(""), statusManajemen("") {}

    OwnerEmployee(string nama, string alamat, int usia, string gender,
                  int idE, string posisi, string email, double gaji,
                  int idP, string namaBisnis, string startUpDate, double pendapatan,
                  int idOE, string persentaseKepemilikan, string statusManajemen)
        : Person(nama, alamat, usia, gender),
          Employee(nama, alamat, usia, gender, idE, posisi, email, gaji),
          Pengusaha(nama, alamat, usia, gender, idP, namaBisnis, startUpDate, pendapatan),
          idOE(idOE), persentaseKepemilikan(persentaseKepemilikan), statusManajemen(statusManajemen) {}

    int getIdOE() const { return idOE; }
    string getPersentaseKepemilikan() const { return persentaseKepemilikan; }
    string getStatusManajemen() const { return statusManajemen; }

    double hitungTotalKompensasi() const {
        return hitungGajiTahunan() + (hitungProfit() * 0.5);
    }

    OwnerEmployee& operator=(const OwnerEmployee& other) {
        if (this != &other) {
            Person::operator=(other);
            Employee::operator=(other);
            Pengusaha::operator=(other);
            idOE = other.idOE;
            persentaseKepemilikan = other.persentaseKepemilikan;
            statusManajemen = other.statusManajemen;
        }
        return *this;
    }
};

#endif