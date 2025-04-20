#include "App.h"
#include "Dokumen.h"
#include "Paket.h"
#include "FragileItem.h"
#include "Kurir.h"
#include "Pengiriman.h"
#include "Tracking.h"

#include <iostream>
#include <memory>

void App::run() {
    auto barangList = muatBarangDariFile("data/daftar_barang.txt");
    std::cout << "\n=== DATA BARANG YANG DIMUAT ===\n";
    for (const auto& b : barangList) {
        b->info();
        std::cout << "-----------------------------\n";
    }

    std::cout << "=== SIMULASI PENGIRIMAN ===" << std::endl;

    // 1. Buat barang (Dokumen, Paket, FragileItem)
    auto dokumen = std::make_shared<Dokumen>("B001", "Surat Penting", 0.2, "Andi", "Budi", 12);
    auto paket = std::make_shared<Paket>("B002", "Paket Buku", 2.5, "Citra", "Dina", 30, 20, 10);
    auto fragile = std::make_shared<FragileItem>("B003", "Vas Kaca", 1.0, "Eka", "Feri", true);

    // 2. Buat kurir
    Kurir kurir("K001", "Joko", "08123456789");

    // 3. Buat pengiriman (misal kirim dokumen)
    Pengiriman pengiriman("P001", dokumen, kurir);
    pengiriman.info();

    // 4. Tracking status
    Tracking tracking("P001");
    tracking.tambahLog("Paket sedang diproses");
    pengiriman.updateStatus("Dalam perjalanan");
    tracking.tambahLog("Kurir mengambil paket");
    pengiriman.updateStatus("Terkirim");
    tracking.tambahLog("Paket berhasil dikirim");

    std::cout << "\n--- TRACKING ---\n";
    tracking.tampilkanLog();
    tracking.simpanKeFile("data/tracking_log.txt");

    std::cout << "\n[SIMULASI SELESAI]\n";
}

#include <fstream>
#include <sstream>

std::vector<std::shared_ptr<Barang>> App::muatBarangDariFile(const std::string& filepath) {
    std::vector<std::shared_ptr<Barang>> daftar;
    std::ifstream file(filepath);
    std::string baris;

    while (std::getline(file, baris)) {
        std::stringstream ss(baris);
        std::string tipe;
        std::getline(ss, tipe, '|');

        if (tipe == "Dokumen") {
            std::string id, nama, pengirim, penerima;
            double berat;
            int halaman;
            std::getline(ss, id, '|');
            std::getline(ss, nama, '|');
            ss >> berat; ss.ignore();
            std::getline(ss, pengirim, '|');
            std::getline(ss, penerima, '|');
            ss >> halaman;
            daftar.push_back(std::make_shared<Dokumen>(id, nama, berat, pengirim, penerima, halaman));
        } else if (tipe == "Paket") {
            std::string id, nama, pengirim, penerima;
            double berat, p, l, t;
            std::getline(ss, id, '|');
            std::getline(ss, nama, '|');
            ss >> berat; ss.ignore();
            std::getline(ss, pengirim, '|');
            std::getline(ss, penerima, '|');
            ss >> p; ss.ignore(); ss >> l; ss.ignore(); ss >> t;
            daftar.push_back(std::make_shared<Paket>(id, nama, berat, pengirim, penerima, p, l, t));
        } else if (tipe == "FragileItem") {
            std::string id, nama, pengirim, penerima;
            double berat;
            int asuransiInt;
            std::getline(ss, id, '|');
            std::getline(ss, nama, '|');
            ss >> berat; ss.ignore();
            std::getline(ss, pengirim, '|');
            std::getline(ss, penerima, '|');
            ss >> asuransiInt;
            daftar.push_back(std::make_shared<FragileItem>(id, nama, berat, pengirim, penerima, asuransiInt == 1));
        }
    }

    return daftar;
}

