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
