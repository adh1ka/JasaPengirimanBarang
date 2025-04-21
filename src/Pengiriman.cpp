#include "Pengiriman.h"
#include <iostream>

Pengiriman::Pengiriman(std::string id, std::shared_ptr<Barang> barang, Kurir kurir, std::string kotaTujuan)
    : idPengiriman(id), barang(barang), kurir(kurir), kotaTujuan(kotaTujuan), status("Diproses") {}

void Pengiriman::prosesPengiriman() {
    if (kurir.getKapasitas() < barang->getBerat()) {
        std::cout << "Kapasitas kurir tidak mencukupi.\n";
        return;
    }
    updateStatus("Dalam perjalanan");
    std::cout << kurir.pilihRute(kotaTujuan) << "\n";
}

void Pengiriman::updateStatus(const std::string& statusBaru) {
    status = statusBaru;
}

void Pengiriman::info() const {
    std::cout << "ID Pengiriman: " << idPengiriman << "\n";
    barang->info();
    kurir.info();
    std::cout << "Tujuan: " << kotaTujuan << "\n"
              << "Status: " << status << "\n";
}

std::string Pengiriman::getIdPengiriman() const {
    return idPengiriman;
}
