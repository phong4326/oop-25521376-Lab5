#ifndef CHUNGCU_H
#define CHUNGCU_H

#include"GiaoDich.h"

class ChungCu : public GiaoDich
{
private:
    std::string maCan;
    int viTriTang;
    static int soLuongCHUNGCU;
public:
    ChungCu() { soLuongCHUNGCU++; }
    ~ChungCu() { soLuongCHUNGCU--; }

    void Nhap() override;
    void Xuat() const override;
    double thanhTien() const override;

    static int getSoLuong() { return soLuongCHUNGCU; }
};

#endif