#ifndef QUANLYHOCVU_H
#define QUANLYHOCVU_H

#include "SinhVien.h"
#include <vector>

class QuanLyHocVu {
private:
    std::vector<SinhVien*> dsSV;
public:
    QuanLyHocVu() = default;
    ~QuanLyHocVu();

    void xuatDanhSach(int Option) const; // 1: tat ca, 2: dat tot nghiep, 3: chua tot nghiep
    void thongKeSVDiemCaoNhat() const;
    void demSVRuoiTungLoai() const;

    friend std::istream& operator>>(std::istream& in, QuanLyHocVu& ql);
};

#endif