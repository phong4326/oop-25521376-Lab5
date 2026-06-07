#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H

#include "NhanVien.h"

class kiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;
public:
    void Nhap() override;
    void Xuat() const override;
    double tinhLuong() const override;
};

#endif