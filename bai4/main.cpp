#include "congTyHoanCau.h"

int main() {
    congTyHoanCau ct;
    try {
        std::cin >> ct;
        std::cout << "\nDanh Sach Nhan Vien\n"; ct.Xuat();
        ct.xuatDuoiChuanTrungBinh();
        std::cout << "\n"; ct.xuatCucTriGiongLoai();
    } catch(const std::exception& e) {
        std::cerr << "[XU LY CONG TY BI LOI]: " << e.what() << "\n";
    }
    return 0;
}
//g++ NhanVien.cpp lapTrinhVien.cpp kiemChungVien.cpp congTyHoanCau.cpp main.cpp -o main