#include <iostream>

// 定义concept，定义Type必须addable
//定义概念：使用 requires 关键字定义一个概念，说明一种类型必须满足的条件。
//应用约束：在函数模板中使用 requires 关键字应用概念作为约束，确保模板参数符合特定概念
template<typename T>
concept Addable = requires (T a, T b) {
    a + b;
};

template <typename Type> 
requires Addable<Type> 
Type add(Type a, Type b) {
    return a + b;
}

template <typename Type> 
Type myMin(Type a, Type b) {
    return a < b ? a : b;     
}

int main() {
    std::cout << myMin<int>(3, 4) << std::endl;
    std::cout << add<int>(3, 4) << std::endl;
    std::cout << add<double>(3.2, 4) << std::endl;
    return 0;
}