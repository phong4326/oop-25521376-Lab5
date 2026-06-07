#ifndef NVVANPHONG_H
#define NVVANPHONG_H

#include"NhanVien.h"

class nvVanPhong : public NhanVien
{
private:
    int soNgayLamViec;
public:
    void Nhap() override;
    void Xuat() const override;
    double tinhLuong() const override;
};

#endif