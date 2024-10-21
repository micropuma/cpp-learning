#include <iostream>  

class Base {
public:
    virtual ~Base() {} 
    virtual void print() {
        std::cout << "This is Base";
    }
};

class Derived : public Base{
public:  
    void print() {
        std::cout << "This is Derived";
    }
};

int main() {
    Derived d;
    Base* b = &d;
    
    dynamic_cast<Derived*>(b);
    b->print();
    
    return 0;
}