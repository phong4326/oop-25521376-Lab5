#include "dsNhanVien.h"
#include "nvVanPhong.h"
#include "nvSanXuat.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

NhanVien* dsNhanVien::taoNhanVien(int loai) {
    if (loai == 1) return new nvSanXuat();
    if (loai == 2) return new nvVanPhong();
    return nullptr;
}

std::istream& operator>>(std::istream& in, dsNhanVien& ds) {
    int n;
    std::cout << "Nhap so luong nhan vien: "; in >> n;
    if (n <= 0) return in;

    for (int i = 0; i < n; i++) {
        std::cout << "Chon loai (1: San Xuat, 2: Van Phong): ";
        int loai; in >> loai;
        
        NhanVien* nv = dsNhanVien::taoNhanVien(loai);
        if (nv != nullptr) {
            nv->Nhap();
            ds.list.push_back(nv);
        }
    }
    return in;
}

void dsNhanVien::Xuat() const {
    if (list.empty()) { std::cout << "Danh sach trong.\n"; return; }
    for (const auto* nv : list) {
        nv->Xuat();
    }
}

double dsNhanVien::tongLuong() const {
    double sum = 0;
    for (const auto* nv : list) sum += nv->tinhLuong();
    return sum;
}

const NhanVien& dsNhanVien::sanXuatLuongThapNhat() const {
    std::vector<NhanVien*> dsSX;
    for (NhanVien* nv : list) {
        if (dynamic_cast<nvSanXuat*>(nv) != nullptr) {
            dsSX.push_back(nv);
        }
    }
    if (dsSX.empty()) throw std::runtime_error("Khong co nhan vien san xuat!");

    auto it = std::min_element(dsSX.begin(), dsSX.end(), [](const NhanVien* a, const NhanVien* b) {
        return a->tinhLuong() < b->tinhLuong();
    });
    return *(*it);
}

const NhanVien& dsNhanVien::vanPhongTuoiCaoNhat() const {
    std::vector<NhanVien*> dsVP;
    for (NhanVien* nv : list) {
        if (dynamic_cast<nvVanPhong*>(nv) != nullptr) {
            dsVP.push_back(nv);
        }
    }
    if (dsVP.empty()) throw std::runtime_error("Khong co nhan vien van phong!");

    auto it = std::min_element(dsVP.begin(), dsVP.end(), [](const NhanVien* a, const NhanVien* b) {
        return a->getDate() < b->getDate();
    });
    return *(*it);
}

dsNhanVien::~dsNhanVien() {
    for (NhanVien* nv : list) delete nv;
    list.clear();
}