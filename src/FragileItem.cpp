#include "FragileItem.h"
#include <iostream>

FragileItem::FragileItem(std::string id, std::string nama, double berat,
                         std::string pengirim, std::string penerima,
                         bool perluAsuransi)
    : Barang(id, nama, berat, pengirim, penerima), perluAsuransi(perluAsuransi) {}

void FragileItem::info() const {
    Barang::info();
    std::cout << "Tipe: Fragile Item, Perlu Asuransi: " 
              << (perluAsuransi ? "Ya" : "Tidak") << "\n";
}

double FragileItem::hitungBiaya() const {
    // Biaya dasar berdasarkan berat + biaya asuransi jika perlu
    double biaya = berat * 15000; // 15.000 per kg
    if (perluAsuransi) {
        biaya += 20000; // Tambah biaya asuransi jika diperlukan
    }
    return biaya;
}
