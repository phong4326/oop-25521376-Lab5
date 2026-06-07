#include "dsNhanVien.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    dsNhanVien congTy;

    try {
        cin >> congTy;
    } catch (const exception& e) {
        cerr << "[LOI NHAP LIEU]: " << e.what();
        return 1;
    }

    cout << "DANH SACH NHAN VIEN CONG TY:\n";
    congTy.Xuat();

    cout << "Tong luong cong ty phai chi tra: " << (size_t)congTy.tongLuong() << " VND";

    try {
        const NhanVien& nv = congTy.sanXuatLuongThapNhat();
        cout << "\nNhan vien San Xuat luong thap nhat: " << nv.getHoTen() 
             << " (" << (size_t)nv.tinhLuong() << " VND)";
    } catch (const runtime_error& e) {
        cout << "\n[THONG BAO]: " << e.what();
    }

    try {
        const NhanVien& nv = congTy.vanPhongTuoiCaoNhat();
        cout << "\nNhan vien Van Phong lon tuoi nhat: " << nv.getHoTen() 
             << " Ngay sinh: " << nv.getDate();
    } catch (const runtime_error& e) {
        cout << "\n[THONG BAO]: " << e.what();
    }
    return 0;
}
//g++ main.cpp NhanVien.cpp nvVanPhong.cpp nvSanXuat.cpp dsNhanVien.cpp -o main