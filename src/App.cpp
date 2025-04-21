#include "App.h"
#include "Dokumen.h"
#include "Paket.h"
#include "FragileItem.h"
#include "Kurir.h"
#include "Pengiriman.h"
#include "Tracking.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <algorithm>


void App::run() {
    int pilihan;
    do {
        std::cout << "\n=== MENU UTAMA ===\n";
        std::cout << "1. Tambah Barang\n";
        std::cout << "2. Lihat Daftar Barang\n";
        std::cout << "3. Buat Pengiriman\n";
        std::cout << "4. Lihat Tracking Log\n";
        std::cout << "0. Keluar\n";
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;
        std::cin.ignore();

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanBarang(); break;
            case 3: buatPengiriman(); break;
            case 4: tampilkanTracking(); break;
            case 0: std::cout << "Keluar dari aplikasi.\n"; break;
            default: std::cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}

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

void App::tambahBarang() {
    std::ofstream file("data/daftar_barang.txt", std::ios::app);
    int jenis;
    std::cout << "Jenis Barang:\n1. Dokumen\n2. Paket\n3. Fragile Item\nPilih: ";
    std::cin >> jenis; std::cin.ignore();

    std::string id, nama, pengirim, penerima;
    double berat;

    std::cout << "ID: "; std::getline(std::cin, id);
    std::cout << "Nama: "; std::getline(std::cin, nama);
    std::cout << "Berat (kg): "; std::cin >> berat; std::cin.ignore();
    std::cout << "Pengirim: "; std::getline(std::cin, pengirim);
    std::cout << "Penerima: "; std::getline(std::cin, penerima);

    if (jenis == 1) {
        int halaman;
        std::cout << "Jumlah Halaman: "; std::cin >> halaman;
        file << "Dokumen|" << id << "|" << nama << "|" << berat << "|"
             << pengirim << "|" << penerima << "|" << halaman << "\n";
    } else if (jenis == 2) {
        double p, l, t;
        std::cout << "Panjang Lebar Tinggi (cm): ";
        std::cin >> p >> l >> t;
        file << "Paket|" << id << "|" << nama << "|" << berat << "|"
             << pengirim << "|" << penerima << "|" << p << "|" << l << "|" << t << "\n";
    } else if (jenis == 3) {
        int asuransi;
        std::cout << "Perlu Asuransi? (1=Ya, 0=Tidak): "; std::cin >> asuransi;
        file << "FragileItem|" << id << "|" << nama << "|" << berat << "|"
             << pengirim << "|" << penerima << "|" << asuransi << "\n";
    } else {
        std::cout << "Jenis tidak dikenal.\n";
    }

    file.close();
    std::cout << "Barang berhasil ditambahkan.\n";

    // Tampilkan biaya barang yang baru ditambahkan
    auto list = muatBarangDariFile("data/daftar_barang.txt");
    auto addedItem = list.back();
    addedItem->info();  // Info barang yang baru ditambahkan
    std::cout << "Biaya Pengiriman: " << addedItem->hitungBiaya() << " IDR\n";
}


void App::tampilkanBarang() {
    auto list = muatBarangDariFile("data/daftar_barang.txt");
    if (list.empty()) {
        std::cout << "Tidak ada barang.\n";
        return;
    }

    std::cout << "\n=== DAFTAR BARANG ===\n";
    for (const auto& b : list) {
        b->info();  // Tampilkan info barang
        std::cout << "Biaya Pengiriman: " << b->hitungBiaya() << " IDR\n";
        std::cout << "---------------------------\n";
    }
}


void App::buatPengiriman() {
    std::string idPengiriman, idBarang, idKurir, namaKurir, telpKurir, kendaraanKurir, kotaTujuan;
    double kapasitasKurir;
    std::cout << "ID Pengiriman: "; std::getline(std::cin, idPengiriman);
    std::cout << "ID Barang (yang sudah ditambahkan): "; std::getline(std::cin, idBarang);
    std::cout << "ID Kurir: "; std::getline(std::cin, idKurir);
    std::cout << "Nama Kurir: "; std::getline(std::cin, namaKurir);
    std::cout << "No Telepon: "; std::getline(std::cin, telpKurir);
    std::cout << "Kendaraan: "; std::getline(std::cin, kendaraanKurir);
    std::cout << "Kapasitas Kendaraan (kg): "; std::cin >> kapasitasKurir;
    std::cin.ignore();
    std::cout << "Kota Tujuan (Contoh: Jakarta, Bandung, Semarang, dll): ";
    std::getline(std::cin, kotaTujuan);

    auto barangList = muatBarangDariFile("data/daftar_barang.txt");
    auto it = std::find_if(barangList.begin(), barangList.end(), [&](const auto& b) {
        return b->getId() == idBarang;
    });

    if (it == barangList.end()) {
        std::cout << "Barang tidak ditemukan.\n";
        return;
    }

    Kurir kurir(idKurir, namaKurir, telpKurir, kendaraanKurir, kapasitasKurir);
    Pengiriman pengiriman(idPengiriman, *it, kurir, kotaTujuan);

    pengiriman.prosesPengiriman();
    pengiriman.updateStatus("Diproses");

    Tracking track(idPengiriman);
    track.tambahLog("Paket dikirim ke " + kotaTujuan);
    track.simpanKeFile("data/tracking_log.txt");

    std::ofstream out("data/pengiriman.txt", std::ios::app);
    out << idPengiriman << "|" << idBarang << "|" << idKurir << "|" << kotaTujuan << "|" << "Diproses\n";
    out.close();

    std::cout << "Pengiriman berhasil dibuat dan diproses.\n";
}


void App::tampilkanTracking() {
    std::ifstream file("data/tracking_log.txt");
    std::string baris;

    if (!file) {
        std::cout << "Tracking log belum tersedia.\n";
        return;
    }

    std::cout << "\n=== TRACKING LOG ===\n";
    while (std::getline(file, baris)) {
        std::cout << baris << "\n";
    }
    file.close();
}
