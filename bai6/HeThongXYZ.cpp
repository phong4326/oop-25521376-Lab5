#include"HeThongXYZ.h"

void HeThongXYZ::Nhap(const std::string& pathIn) {
    std::ifstream fin(pathIn);
    if (!fin.is_open()) throw std::runtime_error("Khong mo duoc file input " + pathIn);

    //int x, y, z;
    if (!(fin >> x >> y >> z)) return;

    //Nhap A
    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new KhachHangA();
        kh->Nhap(fin);
        list.push_back(kh);
    }
    //Nhap B
    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new KhachHangB();
        kh->Nhap(fin);
        list.push_back(kh);
    }
    //Nhap C
    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new KhachHangC();
        kh->Nhap(fin);
        list.push_back(kh);
    }
    fin.close();
}

void HeThongXYZ::Xuat(const std::string& pathOut) const {
    std::ofstream fout(pathOut);
    if (!fout.is_open()) throw std::runtime_error("Khong mo duoc file output de ghi dữ liệu!");

    fout << std::fixed << std::setprecision(0);
    fout << x << " " << y << " " << z << "\n";
    double tongDoanhThu = 0;

    for (const auto* kh : list) {
        fout << kh->getTen() << "\n";
        fout << kh->tinhTienTra() << "\n";
        tongDoanhThu += kh->tinhTienTra();
    }
    fout << tongDoanhThu;
    fout.close();
}

HeThongXYZ::~HeThongXYZ() {
    for (auto* kh : list) delete kh;
    list.clear();
}