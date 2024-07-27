#include "fraction.h"
#include <algorithm>
#include <math.h>

using std::cout;
using std::endl;
using std::to_string;

bool Fraction::operator < (const Fraction& rhs) const {
    return _num * rhs._denum < _denum * rhs._num;
}

bool Fraction::operator > (const Fraction& rhs) const {
    return _num * rhs._denum > _denum * rhs._num;
}

Fraction Fraction::operator - (const Fraction& rhs) const {
    int newNum = _num * rhs._denum - _denum * rhs._num;    
    int newDenom = rhs._denum * _denum;
    return Fraction(newNum, newDenom);
}

Fraction& operator += (Fraction& lhs, const Fraction& rhs) {
    lhs._num = lhs._num * rhs._denum + lhs._denum * rhs._num;
    lhs._denum *= rhs._denum;
    lhs.reduce();

    return lhs;
}

// Implementing the * operation in a non-member function
bool operator < (const double& lhs, const Fraction& rhs) {
    double frac = rhs._num / rhs._denum;
    return lhs < frac;
}

// Overloading << to allow for passing Fractions into streams.
std::ostream& operator << (std::ostream& out, const Fraction& target) {
    out << target._num << "/" << target._denum;
    return out;
}

