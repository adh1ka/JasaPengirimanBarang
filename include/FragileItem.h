#ifndef FRAGILEITEM_H
#define FRAGILEITEM_H

#include "Barang.h"

class FragileItem : public Barang {
private:
    bool perluAsuransi;

public:
    FragileItem(std::string id, std::string nama, double berat,
                std::string pengirim, std::string penerima,
                bool perluAsuransi);

    void info() const override;
    double hitungBiaya() const override;
};

#endif
