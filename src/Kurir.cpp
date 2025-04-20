#include "Kurir.h"
#include <iostream>

Kurir::Kurir(std::string id, std::string nama, std::string noTelepon)
    : id(id), nama(nama), noTelepon(noTelepon) {}

std::string Kurir::getId() const { return id; }
std::string Kurir::getNama() const { return nama; }

void Kurir::info() const {
    std::cout << "Kurir: " << nama << " (ID: " << id << ")\n"
              << "Telepon: " << noTelepon << "\n";
}
