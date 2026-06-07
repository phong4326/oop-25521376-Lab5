#ifndef DATE_H
#define DATE_H

#include<iostream>

class Date
{
private:
    int d, m, y;
public:
    Date(int d = 1, int m = 1, int y = 1) : d(d), m(m), y(y) {}
    
    friend std::istream& operator>>(std::istream& in, Date& a) {
        in >> a.d >> a.m >> a.y;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Date& a) {
        out << a.d << "/" << a.m << "/" << a.y;
        return out;
    }
    bool kiemTra(int m, int y) {
        return (this->m == m && this->y == y);
    }

    ~Date() {}
};

#endif