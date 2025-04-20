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
