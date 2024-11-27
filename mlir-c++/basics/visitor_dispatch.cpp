#include <iostream>
#include <variant>

class A {
public:
    void print() { std::cout << "A" << std::endl; }
};

class B {
public:
    void print() { std::cout << "B" << std::endl; }
};

// 定义一个访问者
struct Visitor {
    void operator()(A& a) const {
        std::cout << "Visited A" << std::endl;
        a.print();
    }

    void operator()(B& b) const {
        std::cout << "Visited B" << std::endl;
        b.print();
    }
};

int main() {
    std::variant<A, B> var1 = A();
    std::variant<A, B> var2 = B();

    // 使用 std::visit 来实现多分发
    std::visit(Visitor(), var1);  // 输出: Visited A
    std::visit(Visitor(), var2);  // 输出: Visited B

    return 0;
}
