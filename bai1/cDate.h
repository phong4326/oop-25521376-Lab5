#ifndef CDATE_H
#define CDATE_H

#include<iostream>

class cDate
{
private:
    int d, m, y;
public:
    cDate(int d = 1, int m = 1, int y = 0) : d(d), m(m), y(y) {}
    friend std::istream& operator>>(std::istream& in, cDate& a) {
        in >> a.d >> a.m >> a.y;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const cDate& a) {
        out << a.d << "/" << a.m << "/" << a.y;
        return out;
    }
    bool operator<(const cDate& o) {
        if (this->y != o.y) return this->y < o.y;
        if (this->m != o.m) return this->m < o.m;
        return this->d < o.d;
    }
    ~cDate() {}
};

#endif