#ifndef DOKUMEN_H
#define DOKUMEN_H

#include "Barang.h"

class Dokumen : public Barang {
private:
    int jumlahHalaman;

public:
    Dokumen(std::string id, std::string nama, double berat,
            std::string pengirim, std::string penerima, int jumlahHalaman);

    void info() const override;
};

#endif
