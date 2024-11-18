#include <iostream>
#include <type_traits>
#include <vector>
#include <memory>

// 前置声明
class Circle;
class Rectangle;

// 抽象访问者
class ShapeVisitor {
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
};

// 抽象形状类
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// 圆形类
class Circle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

// 矩形类
class Rectangle : public Shape {
public:
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

// 具体访问者，打印形状的类型
class ShapePrinter : public ShapeVisitor {
public:
    void visit(Circle& circle) override {
        std::cout << "This is a Circle." << std::endl;
    }

    void visit(Rectangle& rectangle) override {
        std::cout << "This is a Rectangle." << std::endl;
    }
};

int main() {
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    Shapes shapes;
    shapes.emplace_back(std::make_unique<Circle>());
    shapes.emplace_back(std::make_unique<Rectangle>());

    ShapePrinter printer;
    for (auto& s : shapes) {
        s->accept(printer);  // 每个形状接受访问者
    } 

    return 0;
}
