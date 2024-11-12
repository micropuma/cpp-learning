#include <bits/c++config.h>
#include <iostream>
#include <complex>

using namespace std;

template<typename T>
concept SupportLessThan = requires (T x) { x < x;};

template<typename T> 
requires std::copyable<T> && SupportLessThan<T>
T myMax(T& a, T&b) {
    return (b < a) ? a : b;
}

int main() {
    complex<int> a(3);
    complex<int> b(4);
    complex<int> c = myMax(a, b);

    return 0;
}