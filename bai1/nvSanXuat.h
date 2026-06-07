#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#include"NhanVien.h"

class nvSanXuat : public NhanVien
{
private:
    double luongCanBan;
    int soSanPham;
public:
    nvSanXuat() {};
    double tinhLuong() const override;
    void Nhap() override;
    void Xuat() const override;
    ~nvSanXuat() override {};
};

#endif