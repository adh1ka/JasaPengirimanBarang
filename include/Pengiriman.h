#ifndef PENGIRIMAN_H
#define PENGIRIMAN_H

#include <vector>
#include <string>
#include "Kurir.h"

class Pengiriman {
public:
    void prosesPengiriman();
    void distribusiBarang();
    std::string tentukanZona(const std::string& alamat);
};

#endif
