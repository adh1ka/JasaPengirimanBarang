#include "Kurir.h"

Kurir::Kurir(std::string nama, std::string id, std::string kendaraan, int kapasitas)
    : nama(nama), id(id), kendaraan(kendaraan), kapasitas(kapasitas) {}

std::string Kurir::getID() const { return id; }
std::string Kurir::getNama() const { return nama; }
std::string Kurir::getKendaraan() const { return kendaraan; }
int Kurir::getKapasitas() const { return kapasitas; }
