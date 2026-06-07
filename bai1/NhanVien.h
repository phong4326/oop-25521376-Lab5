#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>
#include "cDate.h"

class NhanVien {
protected:
    std::string hoTen;
    cDate ngaySinh;
public:
    NhanVien() = default;
    virtual ~NhanVien() = default;

    virtual void Nhap();
    virtual void Xuat() const;
    
    virtual double tinhLuong() const = 0; 
    cDate getDate() const { return ngaySinh; }
    std::string getHoTen() const { return hoTen; }
};
#endif