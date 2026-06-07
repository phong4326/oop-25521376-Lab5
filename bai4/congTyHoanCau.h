#ifndef CONGTYHOANCAU_H
#define CONGTYHOANCAU_H

#include "NhanVien.h"
#include <vector>

class congTyHoanCau {
private:
    std::vector<NhanVien*> dsNV;
public:
    congTyHoanCau() = default;
    ~congTyHoanCau();

    void Xuat() const;
    double tinhLuongTrungBinh() const;
    void xuatDuoiChuanTrungBinh() const;
    void xuatCucTriGiongLoai() const;

    friend std::istream& operator>>(std::istream& in, congTyHoanCau& ct);
};

#endif