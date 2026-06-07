#include"ChungCu.h"

void ChungCu::Nhap() {
    GiaoDich::Nhap();
    std::cin.ignore();
    std::cout << "Nhap ma can ho: ";
    std::getline(std::cin, maCan);
    std::cout << "Nhap vi tri tang: ";
    std::cin >> viTriTang;
    std::cout << "Nhap dien tich: "; 
    std::cin >> dienTich;
    if (viTriTang <= 0) throw std::invalid_argument("Vi tri tang khong hop le!");
}

void ChungCu::Xuat() const {
    GiaoDich::Xuat();
    std::cout << "Ma Can: " << maCan 
              << " | Vi Tri Tang: " << viTriTang
              << std::fixed << std::setprecision(0)
              << " | Dien Tich: " << dienTich
              << " | Thanh Tien: " << thanhTien() << " VND\n";
}

double ChungCu::thanhTien() const {
    if (viTriTang == 1) return dienTich * donGia * 2.0;
    else if ( viTriTang >= 15) return dienTich * donGia * 1.2;
    return dienTich * donGia;
}

int ChungCu::soLuongCHUNGCU = 0;