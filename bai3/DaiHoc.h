#ifndef DAIHOC_H
#define DAIHOC_H

#include "SinhVien.h"

class DaiHoc : public SinhVien {
private:
    std::string tenLuanVan;
    double diemLuanVan;
public:
    void Nhap() override;
    void Xuat() const override;
    bool duDieuKienTotNghiep() const override;
};

#endif