#include "NhanVien.h"
#include <limits>

void NhanVien::Nhap() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ma NV: "; std::getline(std::cin, maNV);
    std::cout << "Ho ten: "; std::getline(std::cin, hoTen);
    std::cout << "Tuoi: "; std::cin >> tuoi;
    std::cin.ignore();
    std::cout << "SDT: "; std::getline(std::cin, sdt);
    std::cout << "Email: "; std::getline(std::cin, email);
    std::cout << "Luong co ban: "; std::cin >> luongCoBan;
    if (tuoi <= 0 || luongCoBan < 0) throw std::invalid_argument("Thong tin gia tri so khong hop le!");
}

void NhanVien::Xuat() const {
    std::cout << "ID: " << maNV << " | Ten: " << hoTen << " | Tuoi: " << tuoi
              << "\nLien Lac: " << email << " | SDT: " << sdt << "\n";
}