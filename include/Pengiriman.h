#ifndef PENGIRIMAN_H
#define PENGIRIMAN_H

#include "Barang.h"
#include "Kurir.h"
#include <string>
#include <memory>

class Pengiriman {
private:
    std::string idPengiriman;
    std::shared_ptr<Barang> barang;
    Kurir kurir;
    std::string status;
    std::string kotaTujuan;

public:
    Pengiriman(std::string id, std::shared_ptr<Barang> barang, Kurir kurir, std::string kotaTujuan);

    void prosesPengiriman();
    void updateStatus(const std::string& statusBaru);
    void info() const;
    std::string getIdPengiriman() const;
};

#endif
