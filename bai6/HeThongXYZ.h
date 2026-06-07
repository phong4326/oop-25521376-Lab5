#ifndef HETHONGXYZ_H
#define HETHONGXYZ_H

#include"KhachHang.h"
#include"KhachHangA.h"
#include"KhachHangB.h"
#include"KhachHangC.h"
#include<vector>
#include<fstream>
#include<iomanip>

class HeThongXYZ
{
private:
    int x, y, z;
    std::vector<KhachHang*> list;
public:
    HeThongXYZ() = default;
    ~HeThongXYZ();

    void Nhap(const std::string& pathIn);
    void Xuat(const std::string& pathOut) const;

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
};

#endif