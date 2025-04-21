#ifndef KURIR_H
#define KURIR_H

#include <string>

class Kurir {
private:
    std::string id;
    std::string nama;
    std::string noTelepon;
    std::string kendaraan;
    double kapasitas;

public:
    Kurir(std::string id, std::string nama, std::string noTelepon, std::string kendaraan, double kapasitas);

    std::string getId() const;
    std::string getNama() const;
    std::string getKendaraan() const;
    double getKapasitas() const;
    void info() const;

    std::string pilihRute(const std::string& kotaTujuan);
};

#endif