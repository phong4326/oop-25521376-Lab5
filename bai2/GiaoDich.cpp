#include"GiaoDich.h"
#include<limits>

void GiaoDich::Nhap() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nhap ma giao dich: "; 
    std::getline(std::cin, maGiaoDich);
    std::cout << "Nhap ngay giao dich (dd mm yyyy): "; 
    std::cin >> ngayGiaoDich;
    std::cout << "Nhap don gia: "; 
    std::cin >> donGia;
}

void GiaoDich::Xuat() const {
    std::cout << "Ma: " << maGiaoDich
              << " | Ngay GD: " << ngayGiaoDich
              << std::fixed << std::setprecision(0)
              << " | Don Gia: " << donGia << "\n";
}