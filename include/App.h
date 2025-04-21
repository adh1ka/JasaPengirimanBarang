#ifndef APP_H
#define APP_H
#include <vector>
#include <memory>
#include "Barang.h"

class App {
public:
    void run();

private:
    std::vector<std::shared_ptr<Barang>> muatBarangDariFile(const std::string& filepath);
    void tambahBarang();
    void tampilkanBarang();
    void buatPengiriman();
    void tampilkanTracking();
};

#endif
