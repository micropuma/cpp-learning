#include "StrVector.h"
#include <iostream>

int main() {
    StrVector vec(5, "hello");

    // 使用非const迭代器
    for (StrVector::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
        *it = "world";
    }
    std::cout << std::endl;

    // 使用const迭代器
    for (StrVector::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " ";
        // *it = "new"; // 不允许修改
    }
    std::cout << std::endl;

    // 使用const iterator = can increment the iterator, can dereference and change underlying value
    for (StrVector::const_iterator_mutable it = vec.begin_mutable(); it != vec.end_mutable(); ++it) {
        std::cout << *it << " ";
        *it = "changed";
    }
    std::cout << std::endl;

    // 使用const const迭代器
    for (StrVector::const_const_iterator it = vec.cbegin_const(); it != vec.cend_const(); ++it) {
        std::cout << *it << " ";
        // *it = "new"; // 不允许修改
        // ++it;        // 不允许递增
    }
    std::cout << std::endl;

    return 0;
}