#include <iostream>

template<typename Derived> 
struct Base {
    void name() { (static_cast<Derived*>(this))->impl(); }
};

struct D1 : public Base<D1> {
    void impl() { std::cout << "Derived version 1\n"; } 
};

struct D2 : public Base<D2> {
    void impl() { std::cout << "Derived version 2\n"; }
};

int main() {
    D1 d1;
    D2 d2;
    d1.name();
    d2.name();
}