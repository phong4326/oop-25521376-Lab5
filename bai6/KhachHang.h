#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>

class KhachHang {
protected:
    std::string tenKH;
    int soLuongHang;
    double donGiaHang;
public:
    KhachHang() = default;
    virtual ~KhachHang() = default;

    virtual void Nhap(std::istream& in);
    virtual double tinhTienTra() const = 0;
    std::string getTen() const { return tenKH; }
};

#endif