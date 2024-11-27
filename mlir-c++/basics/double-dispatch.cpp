#include <iostream>
using namespace std;

// 基类：Shape
class Shape {
public:
    // 纯虚函数，要求子类必须实现
    virtual void collideWith(class Shape& shape) = 0;
    virtual void collideWith(class Circle& circle) = 0;  
    virtual void collideWith(class Rectangle& rectangle) = 0;  
};

// 圆形类
class Circle : public Shape {
public:
    // 处理基类调用，进行双重调度
    void collideWith(Shape& shape) override {
        cout << "Circle: reach collideWith(Shape& shape)" << endl;
        shape.collideWith(*this);  // 调用其他形状的 collideWith，传递 *this
    }

    void collideWith(Circle& circle) override {
        cout << "Circle collides with Circle!" << endl;
    }
    
    void collideWith(Rectangle& rectangle) override {
        cout << "Circle collides with Rectangle!" << endl;
    }
};

// 矩形类
class Rectangle : public Shape {
public:
    // 处理基类调用，进行双重调度
    void collideWith(Shape& shape) override {
        cout << "Rectangle: reach collideWith(Shape& shape)" << endl;
        shape.collideWith(*this);  // 调用其他形状的 collideWith，传递 *this
    }

    void collideWith(Circle& circle) override {
        cout << "Rectangle collides with Circle!" << endl;
    }
    
    void collideWith(Rectangle& rectangle) override {
        cout << "Rectangle collides with Rectangle!" << endl;
    }
};

int main() {
    Circle c1 = Circle();
    Rectangle r1 = Rectangle();

    Shape* shape1 = &c1;
    Shape* shape2 = &r1;


    // Double dispatch：c1 和 r1 进行碰撞检测
    shape1->collideWith(*shape2);
    
    return 0;
}
