#include "Paket.h"
#include <iostream>

Paket::Paket(std::string id, std::string nama, double berat,
             std::string pengirim, std::string penerima,
             double panjang, double lebar, double tinggi)
    : Barang(id, nama, berat, pengirim, penerima),
      panjang(panjang), lebar(lebar), tinggi(tinggi) {}

void Paket::info() const {
    Barang::info();
    std::cout << "Tipe: Paket, Dimensi: " << panjang << "x" << lebar << "x" << tinggi << " cm\n";
}
