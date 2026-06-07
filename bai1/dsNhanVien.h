#ifndef DSNHANVIEN_H
#define DSNHANVIEN_H
#include <vector>
#include "NhanVien.h"

class dsNhanVien {
private:
    std::vector<NhanVien*> list;
    static NhanVien* taoNhanVien(int loai);
public:
    dsNhanVien() = default;
    ~dsNhanVien();

    void Xuat() const;
    double tongLuong() const;
    
    const NhanVien& sanXuatLuongThapNhat() const;
    const NhanVien& vanPhongTuoiCaoNhat() const;

    friend std::istream& operator>>(std::istream& in, dsNhanVien& ds);
};
#endif