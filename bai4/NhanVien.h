#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

class NhanVien {
protected:
    std::string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;
public:
    NhanVien() = default;
    virtual ~NhanVien() = default;

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double tinhLuong() const = 0;

    std::string getHoTen() const { return hoTen; }
};

#endif