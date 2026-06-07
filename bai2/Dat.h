#ifndef DAT_H
#define DAT_H

#include"GiaoDich.h"

class Dat : public GiaoDich
{
private:
    std::string loaiDat;
    static int soLuongDAT;
public:
    Dat() { soLuongDAT++; }
    ~Dat() {soLuongDAT--; }
    void Nhap() override;
    void Xuat() const override;
    double thanhTien() const override;

    static int getSoLuong() { return soLuongDAT; } 
};

#endif