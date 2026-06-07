#include"Dat.h"

void Dat::Nhap() {
    GiaoDich::Nhap();
    std::cin.ignore();
    std::cout << "Nhap loai dat: ";
    getline(std::cin, loaiDat);
    std::cout << "Nhap dien tich: "; 
    std::cin >> dienTich;
}

void Dat::Xuat() const {
    GiaoDich::Xuat();
    std::cout << "Loai Dat: " << loaiDat
              << std::fixed << std::setprecision(0)
              << " | Dien Tich: " << dienTich
              << " | Thanh Tien: " << thanhTien() << " VND\n";
}

double Dat::thanhTien() const {
    if (this->loaiDat == "A") return dienTich * donGia * 1.5;
    return dienTich * donGia;
}

int Dat::soLuongDAT = 0;