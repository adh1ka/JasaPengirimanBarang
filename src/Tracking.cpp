#include "Tracking.h"
#include <iostream>
#include <fstream>
#include <ctime>

Tracking::Tracking(const std::string& idPengiriman)
    : idPengiriman(idPengiriman) {}

void Tracking::tambahLog(const std::string& status) {
    // Tambahkan timestamp ke log
    std::time_t now = std::time(nullptr);
    char waktu[100];
    std::strftime(waktu, sizeof(waktu), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    std::string log = "[" + std::string(waktu) + "] " + status;
    logStatus.push_back(log);
}

void Tracking::tampilkanLog() const {
    std::cout << "Tracking Log untuk Pengiriman ID: " << idPengiriman << "\n";
    for (const auto& log : logStatus) {
        std::cout << log << "\n";
    }
}

void Tracking::simpanKeFile(const std::string& filepath) const {
    std::ofstream file(filepath, std::ios::app);
    if (!file) {
        std::cerr << "Gagal membuka file tracking.\n";
        return;
    }

    for (const auto& log : logStatus) {
        file << idPengiriman << " - " << log << "\n";
    }
    file.close();
}
