#include "Barang.h"
#include <iostream>

Barang::Barang(std::string id, std::string nama, double berat,
               std::string pengirim, std::string penerima)
    : id(id), nama(nama), berat(berat), pengirim(pengirim), penerima(penerima) {}

void Barang::info() const {
    std::cout << "Barang: " << nama << " (" << id << ")\n"
              << "Berat: " << berat << " kg\n"
              << "Pengirim: " << pengirim << "\n"
              << "Penerima: " << penerima << "\n";
}

std::string Barang::getId() const { return id; }
double Barang::getBerat() const { return berat; }