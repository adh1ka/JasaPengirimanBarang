#ifndef KURIR_H
#define KURIR_H

#include <string>

class Kurir {
private:
    std::string id;
    std::string nama;
    std::string noTelepon;
    std::string kendaraan;   // Tambahkan atribut kendaraan
    double kapasitas;        // Tambahkan kapasitas (dalam kg)

public:
    Kurir(std::string id, std::string nama, std::string noTelepon, std::string kendaraan, double kapasitas);

    std::string getId() const;
    std::string getNama() const;
    std::string getKendaraan() const;
    double getKapasitas() const;
    
    void info() const;
};

#endif
