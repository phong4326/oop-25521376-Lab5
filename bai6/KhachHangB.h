#ifndef KHACHHANGB_H
#define KHACHHANGB_H

#include "KhachHang.h"
#include <algorithm>

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;
public:
    void Nhap(std::istream& in) override {
        KhachHang::Nhap(in);
        in >> soNamThanThiet;
    }

    double tinhTienTra() const override {
        double Max = std::max(soNamThanThiet * 0.05, 0.5);
        return soLuongHang * donGiaHang * (1 - Max) * 1.1;
    }
};

#endif