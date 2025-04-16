#ifndef KURIR_H
#define KURIR_H

#include <string>

class Kurir {
private:
    std::string nama;
    std::string id;
    std::string kendaraan;
    int kapasitas;

public:
    Kurir(std::string nama, std::string id, std::string kendaraan, int kapasitas);

    std::string getID() const;
    std::string getNama() const;
    std::string getKendaraan() const;
    int getKapasitas() const;
};

#endif
