#include "nvVanPhong.h"
#include <iostream>

void nvVanPhong::Nhap() {
    NhanVien::Nhap();
    std::cout << "Nhap so ngay lam viec: ";
    std::cin >> soNgayLamViec;
    if (soNgayLamViec < 0) throw std::invalid_argument("So ngay lam viec khong duoc am!");
}

void nvVanPhong::Xuat() const {
    NhanVien::Xuat();
    std::cout << " | Loai: Van Phong | Luong: " << (size_t)tinhLuong() << " VND\n";
}

double nvVanPhong::tinhLuong() const {
    return soNgayLamViec * 100000.0;
}