#include "Pengiriman.h"
#include <iostream>

Pengiriman::Pengiriman(std::string id, std::shared_ptr<Barang> barang, Kurir kurir)
    : idPengiriman(id), barang(barang), kurir(kurir), status("Diproses") {}

void Pengiriman::updateStatus(const std::string& statusBaru) {
    status = statusBaru;
}

void Pengiriman::info() const {
    std::cout << "Pengiriman ID: " << idPengiriman << "\n";
    barang->info();
    kurir.info();
    std::cout << "Status: " << status << "\n";
}

std::string Pengiriman::getStatus() const {
    return status;
}

std::string Pengiriman::getIdPengiriman() const {
    return idPengiriman;
}
