#ifndef TRACKING_H
#define TRACKING_H

#include <string>
#include <vector>

class Tracking {
private:
    std::string idPengiriman;
    std::vector<std::string> logStatus;

public:
    Tracking(const std::string& idPengiriman);

    void tambahLog(const std::string& status);
    void tampilkanLog() const;

    void simpanKeFile(const std::string& filepath) const;
};

#endif
