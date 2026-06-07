#include"QuanLyHocVu.h"
#include"CaoDang.h"
#include"DaiHoc.h"
#include<algorithm>

std::istream& operator>>(std::istream& in, QuanLyHocVu& ql) {
    int n; std::cout << "Nhap so luong sinh vien: "; in >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "\nChon he dao tao (1: Cao Dang, 2: Dai Hoc): ";
        int opt; in >> opt;
        SinhVien* sv = nullptr;
        if (opt == 1) sv = new CaoDang();
        else if (opt == 2) sv = new DaiHoc();
        
        if (sv != nullptr) {
            sv->Nhap();
            ql.dsSV.push_back(sv);
        }
    }
    return in;
}

void QuanLyHocVu::xuatDanhSach(int Option) const {
    bool emptyCheck = true;
    int i = 1;
    for (const auto* sv : dsSV) {
        if (Option == 1 || (Option == 2 && sv->duDieuKienTotNghiep()) || (Option == 3 && !sv->duDieuKienTotNghiep())) {
            std::cout << "No." << i++ << " ";
            sv->Xuat();
            emptyCheck = false;
        }
    }
    if (emptyCheck) std::cout << "  (Danh sach khong co phan tu nao thoa man)\n";
}

void QuanLyHocVu::thongKeSVDiemCaoNhat() const {
    std::vector<SinhVien*> dsDH, dsCD;
    for (auto* sv : dsSV) {
        if (dynamic_cast<DaiHoc*>(sv)) dsDH.push_back(sv);
        else if (dynamic_cast<CaoDang*>(sv)) dsCD.push_back(sv);
    }

    if (!dsDH.empty()) {
        auto it = std::max_element(dsDH.begin(), dsDH.end(), [](const SinhVien* a, const SinhVien* b) { return a->getDiemTB() < b->getDiemTB(); });
        std::cout << "\nSV Dai hoc co DTB cao nhat: " << (*it)->getHoTen() << " (" << (*it)->getDiemTB() << ")\n";
    } else std::cout << "\nKhong co sinh vien Dai hoc nao.\n";

    if (!dsCD.empty()) {
        auto it = std::max_element(dsCD.begin(), dsCD.end(), [](const SinhVien* a, const SinhVien* b) { return a->getDiemTB() < b->getDiemTB(); });
        std::cout << "\nSV Cao dang co DTB cao nhat: " << (*it)->getHoTen() << " (" << (*it)->getDiemTB() << ")\n";
    } else std::cout << "\nKhong co sinh vien Cao dang nao.\n";
}

void QuanLyHocVu::demSVRuoiTungLoai() const {
    int failCD = 0, failDH = 0;
    for (const auto* sv : dsSV) {
        if (!sv->duDieuKienTotNghiep()) {
            if (dynamic_cast<const CaoDang*>(sv)) failCD++;
            else if (dynamic_cast<const DaiHoc*>(sv)) failDH++;
        }
    }
    std::cout << "So sinh vien Cao dang KHONG du dieu kien TN: " << failCD << "\n";
    std::cout << "So sinh vien Dai hoc KHONG du dieu kien TN: " << failDH << "\n";
}

QuanLyHocVu::~QuanLyHocVu() {
    for (auto* sv : dsSV) delete sv;
    dsSV.clear();
}