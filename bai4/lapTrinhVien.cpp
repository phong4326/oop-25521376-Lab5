#include "lapTrinhVien.h"

void lapTrinhVien::Nhap() {
    NhanVien::Nhap();
    std::cout << "So gio Overtime: "; std::cin >> soGioOT;
    if (soGioOT < 0) throw std::invalid_argument("Gio OT khong am!");
}

double lapTrinhVien::tinhLuong() const {
    return luongCoBan + soGioOT * 200000.0;
}

void lapTrinhVien::Xuat() const {
    NhanVien::Xuat();
    std::cout << "Nghe: Dev | Luong: " << (size_t)tinhLuong() << " VND\n\n";
}