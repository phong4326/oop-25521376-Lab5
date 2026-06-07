#include "nvSanXuat.h"
#include <iostream>

void nvSanXuat::Nhap() {
    NhanVien::Nhap();
    std::cout << "Nhap luong can ban: "; std::cin >> luongCanBan;
    std::cout << "Nhap so san pham: "; std::cin >> soSanPham;
    if (luongCanBan < 0 || soSanPham < 0) throw std::invalid_argument("Du lieu nhap khong duoc am!");
}

void nvSanXuat::Xuat() const {
    NhanVien::Xuat();
    std::cout << " | Loai: San Xuat  | Luong: " << (size_t)tinhLuong() << " VND\n";
}

double nvSanXuat::tinhLuong() const {
    return luongCanBan + soSanPham * 5000.0;
}