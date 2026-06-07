#include"CaoDang.h"

void CaoDang::Nhap() {
    SinhVien::Nhap();
    std::cout << "    Nhap diem thi tot nghiep: "; std::cin >> diemThiTotNghiep;
    if (diemThiTotNghiep < 0 || diemThiTotNghiep > 10) {
        throw std::invalid_argument("Diem thi tot nghiep khong hop le!");
    }
}

void CaoDang::Xuat() const {
    SinhVien::Xuat();
    std::cout << "\n | Diem thi TN: " << diemThiTotNghiep
              << " | Trang thai: " << (duDieuKienTotNghiep() ? "Tot nghiep" : "Chua tot nghiep")
              << " (Cao Dang)\n";
}

bool CaoDang::duDieuKienTotNghiep() const {
    //120 tin chi ĐTB >= 5 diem thi tot nghiep >= 5
    return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTotNghiep >= 5.0);
}