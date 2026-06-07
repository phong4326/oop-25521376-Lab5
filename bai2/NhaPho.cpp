#include"NhaPho.h"

void NhaPho::Nhap() {
    GiaoDich::Nhap();
    std::cin.ignore();
    std::cout << "Nhap dia chi nha: ";
    std::getline(std::cin, diaChi);
    std::cout << "Nhap loai nha: ";
    getline(std::cin, loaiNha);
    std::cout << "Nhap dien tich: "; 
    std::cin >> dienTich;
}

void NhaPho::Xuat() const {
    GiaoDich::Xuat();
    std::cout << "Loai Nha: " << loaiNha
              << " | Dia Chi: " << diaChi
              << std::fixed << std::setprecision(0)
              << " | Dien Tich: " << dienTich
              << " | Thanh Tien: " << thanhTien() << " VND\n";
}

double NhaPho::thanhTien() const {
    if (loaiNha == "cao cap") return dienTich * donGia;
    return dienTich * donGia * 0.9;
}

int NhaPho::soLuongNHA = 0;