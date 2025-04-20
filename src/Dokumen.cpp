#include "Dokumen.h"
#include <iostream>

Dokumen::Dokumen(std::string id, std::string nama, double berat,
                 std::string pengirim, std::string penerima, int jumlahHalaman)
    : Barang(id, nama, berat, pengirim, penerima), jumlahHalaman(jumlahHalaman) {}

void Dokumen::info() const {
    Barang::info();
    std::cout << "Tipe: Dokumen, Halaman: " << jumlahHalaman << "\n";
}

double Dokumen::hitungBiaya() const {
    // Biaya berdasarkan berat (contoh: tarif 10 ribu per kg)
    return berat * 10000; // contoh tarif: 10.000 per kg
}
