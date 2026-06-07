#ifndef DSGIAODICH_H
#define DSGIAODICH_H

#include"GiaoDich.h"
#include<vector>

class dsGiaoDich
{
private:
    std::vector<GiaoDich*> list;
    static GiaoDich* taoGiaoDich(int loai);
public:
    dsGiaoDich() = default;
    ~dsGiaoDich();

    friend std::istream& operator>>(std::istream& in, dsGiaoDich& ds);
    void XuatDieuKien() const;

    double trungBinhTienChungCu() const;
    const GiaoDich& nhaDatCaoNhat() const;
};

#endif