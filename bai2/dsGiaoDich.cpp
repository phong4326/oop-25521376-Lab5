#include "dsGiaoDich.h"
#include "Dat.h"
#include "NhaPho.h"
#include "ChungCu.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

GiaoDich* dsGiaoDich::taoGiaoDich(int loai) {
    if (loai == 1) return new Dat();
    if (loai == 2) return new NhaPho();
    if (loai == 3) return new ChungCu();
    return nullptr;
}

std::istream& operator>>(std::istream& in, dsGiaoDich& ds) {
    int n;
    std::cout << "Nhap so luong giao dich: "; in >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Chon loai (1: Dat, 2: Nha Pho, 3: Chung Cu): ";
        int loai; in >> loai;
        GiaoDich* gd = dsGiaoDich::taoGiaoDich(loai);
        if (gd != nullptr) {
            gd->Nhap();
            ds.list.push_back(gd);
        }
    }
    return in;
}

void dsGiaoDich::XuatDieuKien() const {
    std::cout << "\n--- Giao dich thang 12 nam 2024 ---\n";
    bool coGd = false;
    for (GiaoDich* gd : list) {
        Date d = gd->getDate(); 
        if (d.kiemTra(12, 2024)) {
            gd->Xuat();
            std::cout << "\n";
            coGd = true;
        }
    }
    if (!coGd) std::cout << "  (Khong co giao dich nao thoa man)\n";
}

double dsGiaoDich::trungBinhTienChungCu() const {
    double tongTien = 0;
    int countCC = 0;
    for (const GiaoDich* gd : list) {
        // Lọc an toàn bằng dynamic_cast
        const ChungCu* cc = dynamic_cast<const ChungCu*>(gd);
        if (cc != nullptr) {
            tongTien += cc->thanhTien();
            countCC++;
        }
    }
    if (countCC == 0) return 0.0;
    return tongTien / countCC;
}

const GiaoDich& dsGiaoDich::nhaDatCaoNhat() const {
    std::vector<GiaoDich*> dsNhaPho;
    for (GiaoDich* gd : list) {
        if (dynamic_cast<NhaPho*>(gd) != nullptr) {
            dsNhaPho.push_back(gd);
        }
    }
    if (dsNhaPho.empty()) {
        throw std::runtime_error("Danh sach khong co giao dich nha pho nao!");
    }
    
    auto it = std::max_element(dsNhaPho.begin(), dsNhaPho.end(), [](const GiaoDich* a, const GiaoDich* b) {
        return a->thanhTien() < b->thanhTien();
    });
    return *(*it);
}

dsGiaoDich::~dsGiaoDich() {
    for (GiaoDich* gd : list) delete gd;
    list.clear();
}