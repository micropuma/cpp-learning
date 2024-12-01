#include <iostream>

// Base class A using CRTP
template <typename Derived>
struct BaseA {
    void doSomething() {
        static_cast<Derived*>(this)->doSomethingA();
    }
};

// Base class B using CRTP
template <typename Derived>
struct BaseB {
    void doSomething() {
        static_cast<Derived*>(this)->doSomethingB();
    }
};

// Derived class inheriting both BaseA and BaseB
struct Derived : public BaseA<Derived>, public BaseB<Derived> {
    void doSomethingA() {
        std::cout << "Doing something from BaseA" << std::endl;
    }

    void doSomethingB() {
        std::cout << "Doing something from BaseB" << std::endl;
    }
};

int main() {
    Derived obj;
    // Ambiguity error! Compiler doesn't know which `doSomething` to call.
    // obj.doSomething();

    // Explicitly call one base class's method to resolve ambiguity
    obj.BaseA<Derived>::doSomething();
    obj.BaseB<Derived>::doSomething();

    return 0;
}
