#include "Pengiriman.h"
#include <iostream>

void Pengiriman::prosesPengiriman() {
    std::cout << "Proses pengiriman dimulai...\n";
    distribusiBarang();
}

void Pengiriman::distribusiBarang() {
    std::cout << "Distribusi barang berdasarkan zona wilayah...\n";
    // Placeholder logika zona & kapasitas
}

std::string Pengiriman::tentukanZona(const std::string& alamat) {
    if (alamat.find("Utara") != std::string::npos) return "Zona Utara";
    if (alamat.find("Selatan") != std::string::npos) return "Zona Selatan";
    if (alamat.find("Timur") != std::string::npos) return "Zona Timur";
    if (alamat.find("Barat") != std::string::npos) return "Zona Barat";
    return "Zona Tidak Diketahui";
}
