#include <iostream>
#include <cmath>
#include <stdio.h>

int squareN(int& num) {
    return std::pow(num, 2);
}

int main() {
    int lvalue = 2;
    auto four = squareN(lvalue);
    auto wrong = squareN(2);

    return 0;
}
