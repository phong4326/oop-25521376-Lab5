#ifndef KHACHHANGC_H
#define KHACHHANGC_H

#include "KhachHang.h"

class KhachHangC : public KhachHang {
public:
    double tinhTienTra() const override {
        return soLuongHang * donGiaHang * 0.5 * 1.1;
    }
};

#endif