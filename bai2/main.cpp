#include "dsGiaoDich.h"
#include "Dat.h"
#include "NhaPho.h"
#include "ChungCu.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    dsGiaoDich vakaLand;

    try {
        cin >> vakaLand;
    } catch (const exception& e) {
        cerr << "[LOI NHAP LIEU CRITICAL]: " << e.what();
        return 1;
    }

    cout << endl;

    cout << "Tong so giao dich Dat: " << Dat::getSoLuong() << "\n";
    cout << "Tong so giao dich Nha Pho: " << NhaPho::getSoLuong() << "\n";
    cout << "Tong so giao dich Chung Cu: " << ChungCu::getSoLuong() << "\n";

    double avgChungCu = vakaLand.trungBinhTienChungCu();
    cout << "Trung binh thanh tien cua Giao dich Chung Cu: " << (size_t)avgChungCu << " VND\n";

    try {
        const GiaoDich& maximumNhaPho = vakaLand.nhaDatCaoNhat();
        cout << "GIAO DICH NHA PHO CO GIA TRI CAO NHAT LUONG TIEN:\n";
        maximumNhaPho.Xuat();
        cout << "\n";
    } catch (const runtime_error& e) {
        cout << "[DA CHAN LOI]: " << e.what() << endl;
    }

    vakaLand.XuatDieuKien();

    return 0;
}
//g++ ChungCu.cpp Dat.cpp dsGiaoDich.cpp GiaoDich.cpp NhaPho.cpp main.cpp -o main