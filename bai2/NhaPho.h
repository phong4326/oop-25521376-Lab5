#ifndef NHAPHO_H
#define NHAPHO_H

#include"GiaoDich.h"

class NhaPho : public GiaoDich
{
private:
    std::string loaiNha, diaChi;
    static int soLuongNHA;
public:
    NhaPho() { soLuongNHA++; }
    ~NhaPho() { soLuongNHA--; }

    void Nhap() override;
    void Xuat() const override;
    double thanhTien() const override;

    static int getSoLuong() { return soLuongNHA; }
};

#endif