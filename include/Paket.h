#ifndef PAKET_H
#define PAKET_H

#include "Barang.h"

class Paket : public Barang {
private:
    double panjang, lebar, tinggi;

public:
    Paket(std::string id, std::string nama, double berat,
          std::string pengirim, std::string penerima,
          double panjang, double lebar, double tinggi);

    void info() const override;
    double hitungBiaya() const override;
};

#endif
