#include "QuanLyHocVu.h"

using namespace std;

int main() {
    QuanLyHocVu hq;
    try {
        cin >> hq;
        cout << endl;
        cout << "\nDanh Sach Sinh Vien\n"; hq.xuatDanhSach(1);
        cout << "\nDanh SACH Sinh Vien Tot Nghiep\n"; hq.xuatDanhSach(2);
        cout << "\nDanh Sach Sinh Vien Chua Tot Nghiep\n"; hq.xuatDanhSach(3);
        hq.thongKeSVDiemCaoNhat();
        cout << "\nThong Ke Chua Tot Nghiep\n"; hq.demSVRuoiTungLoai();
    } catch(const std::exception& e) {
        cout << "\n[DA CHAN LOI]: " << e.what() << "\n";
    }
    return 0;
}
//g++ CaoDang.cpp DaiHoc.cpp QuanLyHocVu.cpp SinhVien.cpp main.cpp -o main