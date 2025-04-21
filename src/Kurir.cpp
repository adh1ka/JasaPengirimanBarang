#include "Kurir.h"
#include <iostream>
#include <vector>
#include <algorithm>

Kurir::Kurir(std::string id, std::string nama, std::string noTelepon, std::string kendaraan, double kapasitas)
    : id(id), nama(nama), noTelepon(noTelepon), kendaraan(kendaraan), kapasitas(kapasitas) {}

std::string Kurir::getId() const { return id; }
std::string Kurir::getNama() const { return nama; }
std::string Kurir::getKendaraan() const { return kendaraan; }
double Kurir::getKapasitas() const { return kapasitas; }

void Kurir::info() const {
    std::cout << "Kurir: " << nama << " (ID: " << id << ")\n"
              << "Telepon: " << noTelepon << "\n"
              << "Kendaraan: " << kendaraan << "\n"
              << "Kapasitas: " << kapasitas << " kg\n";
}

std::string Kurir::pilihRute(const std::string& kotaTujuan) {
    std::vector<std::string> kotaPokok = {
        "Jakarta", "Serang", "Cilegon",
        "Bandung", "Bekasi",
        "Semarang", "Surakarta",
        "Yogyakarta",
        "Surabaya", "Malang"
    };

    std::string kotaLower = kotaTujuan;
    std::transform(kotaLower.begin(), kotaLower.end(), kotaLower.begin(), ::tolower);

    for (auto& kota : kotaPokok) {
        std::string kotaRef = kota;
        std::transform(kotaRef.begin(), kotaRef.end(), kotaRef.begin(), ::tolower);
        if (kotaLower == kotaRef) {
            return "Rute: Express ke " + kota;
        }
    }
    return "Rute: Reguler (Daerah)";
}
