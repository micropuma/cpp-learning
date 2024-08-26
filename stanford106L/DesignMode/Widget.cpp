#include "Widget.h"
#include <iostream>

// 实现类的定义，隐藏在实现文件中
class Widget::Impl {
public:
    void doSomethingImpl() {
        std::cout << "Doing something in the implementation!" << std::endl;
    }
};

// Widget 构造函数
Widget::Widget() : pImpl(std::make_unique<Impl>()) {}

// Widget 析构函数
Widget::~Widget() = default;

// Widget 公共方法
void Widget::doSomething() {
    pImpl->doSomethingImpl();  // 委托给实现类的方法
}
