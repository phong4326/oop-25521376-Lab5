#include"DaiHoc.h"
#include <limits>

void DaiHoc::Nhap() {
    SinhVien::Nhap();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nhap ten luan van: "; std::getline(std::cin, tenLuanVan);
    std::cout << "Nhap diem luan van: "; std::cin >> diemLuanVan;
    if (diemLuanVan < 0 || diemLuanVan > 10) {
        throw std::invalid_argument("Diem luan van khong hop le!");
    }
}

void DaiHoc::Xuat() const {
    SinhVien::Xuat();
    std::cout << "\n | Luan van: " << tenLuanVan 
              << " | diem: " << diemLuanVan 
              << " | Trang thai: " << (duDieuKienTotNghiep() ? "Tot nghiep" : "Chua tot nghiep")
              << " (Dai Hoc)\n";
              
}

bool DaiHoc::duDieuKienTotNghiep() const {
    // du 170 tin chi ĐTB >= 5 Điem luan van >= 5
    return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}