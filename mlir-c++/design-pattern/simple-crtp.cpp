#include <iostream>

template <class Derived> 
struct Base {
    void name() { 
        static_cast<Derived*>(this)->impl(); 
    }
protected:
    ~Base() = default;
};

struct D1 : Base<D1> {
    void impl() { std::cout << "D1" << std::endl; }
};

struct D2: Base<D2> {
    void impl() { std::cout << "D2" << std::endl; }
};

int main() {
    D1 d1;
    D2 d2;
    d1.name();
    d2.name();
    return 0;
}