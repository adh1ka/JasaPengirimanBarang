#ifndef KURIR_H
#define KURIR_H

#include <string>

class Kurir {
private:
    std::string id;
    std::string nama;
    std::string noTelepon;

public:
    Kurir(std::string id, std::string nama, std::string noTelepon);

    std::string getId() const;
    std::string getNama() const;

    void info() const;
};

#endif
