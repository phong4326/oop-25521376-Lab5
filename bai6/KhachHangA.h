#ifndef KHACHHANGA_H
#define KHACHHANGA_H

#include "KhachHang.h"

class KhachHangA : public KhachHang {
public:
    double tinhTienTra() const override {
        return soLuongHang * donGiaHang * 1.1;
    }
};

#endif