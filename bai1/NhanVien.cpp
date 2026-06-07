#include "NhanVien.h"
#include <iostream>

void NhanVien::Nhap() {
    std::cout << "Nhap ho ten: ";
    std::getline(std::cin >> std::ws, hoTen);
    std::cout << "Nhap ngay sinh (dd mm yyyy): ";
    std::cin >> ngaySinh;
}

void NhanVien::Xuat() const {
    std::cout << "Ho ten: " << hoTen << " | Ngay sinh: " << ngaySinh;
}