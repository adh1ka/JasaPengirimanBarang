#ifndef BARANG_H
#define BARANG_H

#include <string>

class Barang {
protected:
    std::string id;
    std::string nama;
    double berat; // dalam kg
    std::string pengirim;
    std::string penerima;

public:
    Barang(std::string id, std::string nama, double berat,
           std::string pengirim, std::string penerima);
    virtual ~Barang() = default;

    virtual void info() const;
    virtual double hitungBiaya() const = 0; // virtual pure function

    std::string getId() const;
    double getBerat() const;
};

#endif
