#ifndef GIAODICH_H
#define GIAODICH_H

#include<iostream>
#include<string>
#include<iomanip>
#include"Date.h"

class GiaoDich
{
protected:
    std::string maGiaoDich;
    Date ngayGiaoDich;
    double donGia, dienTich;
public:
    GiaoDich() = default;
    virtual ~GiaoDich() = default;

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double thanhTien() const = 0;

    Date getDate() const { return ngayGiaoDich; }
};

#endif