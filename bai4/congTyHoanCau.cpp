#include"congTyHoanCau.h"
#include"lapTrinhVien.h"
#include"kiemChungVien.h"
#include<algorithm>

std::istream& operator>>(std::istream& in, congTyHoanCau& ct) {
    int n; std::cout << "Nhap so luong nhan vien Hoan Cau: "; in >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "\nChon vi tri (1: Lap Trinh Vien, 2: Kiem Chung Vien): ";
        int opt; in >> opt;
        NhanVien* nv = nullptr;
        if (opt == 1) nv = new lapTrinhVien();
        else if (opt == 2) nv = new kiemChungVien();

        if (nv != nullptr) {
            nv->Nhap();
            ct.dsNV.push_back(nv);
        }
    }
    return in;
}

void congTyHoanCau::Xuat() const {
    for (const auto* nv : dsNV) nv->Xuat();
}

double congTyHoanCau::tinhLuongTrungBinh() const {
    if (dsNV.empty()) return 0;
    double tong = 0;
    for (const auto* nv : dsNV) tong += nv->tinhLuong();
    return tong / dsNV.size();
}

void congTyHoanCau::xuatDuoiChuanTrungBinh() const {
    double avg = tinhLuongTrungBinh();
    std::cout << "Nhan vien co luong < Muc TB (" << (size_t)avg << " VND)\n";
    for (const auto* nv : dsNV) {
        if (nv->tinhLuong() < avg) {
            std::cout << "  " << nv->getHoTen() << " (" << (size_t)nv->tinhLuong() << " VND)\n";
        }
    }
}

void congTyHoanCau::xuatCucTriGiongLoai() const {
    if (dsNV.empty()) return;
    
    // Toàn công ty max/min
    auto maxNV = std::max_element(dsNV.begin(), dsNV.end(), [](const NhanVien* a, const NhanVien* b) { return a->tinhLuong() < b->tinhLuong(); });
    auto minNV = std::min_element(dsNV.begin(), dsNV.end(), [](const NhanVien* a, const NhanVien* b) { return a->tinhLuong() < b->tinhLuong(); });
    std::cout << "Luong CAO nhat Cong ty: " << (*maxNV)->getHoTen() << " (" << (size_t)(*maxNV)->tinhLuong() << " VND)\n";
    std::cout << "Luong THAP nhat Cong ty: " << (*minNV)->getHoTen() << " (" << (size_t)(*minNV)->tinhLuong() << " VND)\n";

    // Phân tách nhánh
    std::vector<NhanVien*> dsDev, dsTester;
    for (auto* nv : dsNV) {
        if (dynamic_cast<lapTrinhVien*>(nv)) dsDev.push_back(nv);
        else if (dynamic_cast<kiemChungVien*>(nv)) dsTester.push_back(nv);
    }

    if (!dsDev.empty()) {
        auto maxDev = std::max_element(dsDev.begin(), dsDev.end(), [](const NhanVien* a, const NhanVien* b) { return a->tinhLuong() < b->tinhLuong(); });
        std::cout << "Lap trinh vien luong CAO nhat: " << (*maxDev)->getHoTen() << " (" << (size_t)(*maxDev)->tinhLuong() << " VND)\n";
    }
    if (!dsTester.empty()) {
        auto minTester = std::min_element(dsTester.begin(), dsTester.end(), [](const NhanVien* a, const NhanVien* b) { return a->tinhLuong() < b->tinhLuong(); });
        std::cout << "Kiem chung vien luong THAP nhat: " << (*minTester)->getHoTen() << " (" << (size_t)(*minTester)->tinhLuong() << " VND)\n";
    }
}

congTyHoanCau::~congTyHoanCau() {
    for (auto* nv : dsNV) delete nv;
    dsNV.clear();
}