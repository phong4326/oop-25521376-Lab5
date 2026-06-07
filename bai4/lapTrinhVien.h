#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H

#include "NhanVien.h"

class lapTrinhVien : public NhanVien {
private:
    int soGioOT;
public:
    void Nhap() override;
    void Xuat() const override;
    double tinhLuong() const override;
};

#endif