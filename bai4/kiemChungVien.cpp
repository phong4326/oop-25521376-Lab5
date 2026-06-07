#include "kiemChungVien.h"

void kiemChungVien::Nhap() {
    NhanVien::Nhap();
    std::cout << "So loi phat hien: "; std::cin >> soLoiPhatHien;
    if (soLoiPhatHien < 0) throw std::invalid_argument("So loi khong am!");
}

double kiemChungVien::tinhLuong() const {
    return luongCoBan + soLoiPhatHien * 50000.0;
}

void kiemChungVien::Xuat() const {
    NhanVien::Xuat();
    std::cout << "Nghe: Tester | Luong: " << (size_t)tinhLuong() << " VND\n\n";
}