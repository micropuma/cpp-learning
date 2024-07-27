#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric>

class Fraction {
public:
    Fraction(int num, int denum) : _num(num), _denum(denum) { 
        reduce(); 
    }

    // member operator override
    bool operator<(const Fraction &rhs) const;
    bool operator>(const Fraction &rhs) const;
    Fraction operator-(const Fraction &rhs) const;

    // non-member operator override
    friend Fraction &operator+=(Fraction &lhs, const Fraction &rhs);
    friend bool operator<(const double &lhs, const Fraction &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Fraction &target);

private:
    int _num;
    int _denum;

    void reduce() {
        int gcd = std::gcd(_num, _denum);
        _num /= gcd;
        _denum /= gcd;
    }
};

#endif