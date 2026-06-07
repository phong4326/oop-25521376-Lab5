#include "HeThongXYZ.h"

int main() {
    HeThongXYZ heThong;
    try {
        heThong.Nhap("XYZ.INP");
        std::cout << std::endl;
        heThong.Xuat("XYZ.OUT");
    } catch (const std::exception& e) {
        std::cout << "[CRITICAL ERROR]: " << e.what() << "\n";
    }
    return 0;
}
//g++ KhachHang.cpp HeThongXYZ.cpp main.cpp -o main