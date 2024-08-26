#ifndef WIDGET_H
#define WIDGET_H

#include <memory>

class Widget {
public:
    Widget();                   // 构造函数
    ~Widget();                  // 析构函数

    void doSomething();         // 一个公共方法

private:
    class Impl;                 // 实现类的前向声明
    std::unique_ptr<Impl> pImpl; // 指向实现类的智能指针
};

#endif // WIDGET_H
