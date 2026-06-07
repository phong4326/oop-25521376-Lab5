#include "SinhVien.h"
#include <limits>

void SinhVien::Nhap() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nhap MSSV: "; std::getline(std::cin, mssv);
    std::cout << "Nhap ho ten: "; std::getline(std::cin, hoTen);
    std::cout << "Nhap dia chi: "; std::getline(std::cin, diaChi);
    std::cout << "Nhap tong so tin chi: "; std::cin >> tongTinChi;
    std::cout << "Nhap diem trung binh: "; std::cin >> diemTB;
    if (tongTinChi < 0 || diemTB < 0 || diemTB > 10) {
        throw std::invalid_argument("Du lieu hoc tap nhap vao khong hop le!");
    }
}

void SinhVien::Xuat() const {
    std::cout << "MSSV: " << mssv 
              << " | Ten: " << hoTen 
              << " | Tin chi: " << tongTinChi 
              << " | Diem TB: " << diemTB;
}