#ifndef CAODANG_H
#define CAODANG_H

#include "SinhVien.h"

class CaoDang : public SinhVien {
private:
    double diemThiTotNghiep;
public:
    void Nhap() override;
    void Xuat() const override;
    bool duDieuKienTotNghiep() const override;
};

#endif