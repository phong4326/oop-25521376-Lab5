#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>

class SinhVien {
protected:
    std::string mssv, hoTen, diaChi;
    int tongTinChi;
    double diemTB;
public:
    SinhVien() = default;
    virtual ~SinhVien() = default;

    virtual void Nhap();
    virtual void Xuat() const;
    virtual bool duDieuKienTotNghiep() const = 0; // da hinh dieu kien tot nghiep

    double getDiemTB() const { return diemTB; }
    std::string getHoTen() const { return hoTen; }
};

#endif