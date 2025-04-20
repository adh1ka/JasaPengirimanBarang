#include "Kurir.h"
#include <iostream>

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
