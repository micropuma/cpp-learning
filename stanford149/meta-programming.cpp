#include <iostream>

// c++ 的meta编程，是利用模板在编译阶段的特性，提高普通代码的运算速度。
template <unsigned n> 
struct Factorial {
    enum { value = n * Factorial<n-1>::value };
};

// 特例化当n是1
template <>
struct Factorial<0> {
    enum { value = 1 };
};

int main() {
    std::cout << Factorial<10>::value << std::endl;
}