#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Shape {
    virtual auto clone() -> Shape* = 0;  // 返回裸指针
    virtual auto printInfo() const -> void = 0; // 将 printInfo 设为虚函数
    virtual ~Shape() = default;
};

template<typename T>
struct ShapeCRTP : public Shape {
    virtual auto clone() -> Shape* override {
        return new T(*static_cast<T*>(this));  // 使用 new 和 static_cast 创建新对象
    }
};

struct Triangle : public ShapeCRTP<Triangle> {
    auto printInfo() const -> void override {  // 覆盖 printInfo
        cout << "This is Triangle\n";
    }
};

struct Rectangle : public ShapeCRTP<Rectangle> {
    auto printInfo() const -> void override {  // 覆盖 printInfo
        cout << "This is Rectangle\n";
    }
};

int main() {
    vector<Shape*> v;  // 使用裸指针

    v.push_back(new Triangle());  // 使用 new 创建对象
    v.push_back(new Rectangle());
    
    for (const auto a : v) {  // 使用拷贝方式（不要使用引用，因为是裸指针）
        a->printInfo();  // 可以调用虚函数 printInfo
    }

    // 手动删除动态分配的内存
    for (auto a : v) {
        delete a;  // 手动删除
    }
}
