# Difference between static_cast and dynamic_cast  
## Static_cast  
当我们明确我们传入的参数或是数据的类型的时候，用static_cast即可，不会runtime type check。   
```cpp   
void func(void *data) {
  // Conversion from MyClass* -> void* is implicit
  MyClass *c = static_cast<MyClass*>(data);
  ...
}

int main() {
  MyClass c;
  start_thread(&func, &c)  // func(&c) will be called
      .join();
}
```   

## Dynamic_cast  
当我们不清楚object的动态类型的时候，使用dynamic_cast。如果提供的object没法cast到提供的基类类型，返回nullptr。  
`error code:`  
```cpp  
struct Base { };
struct Derived : Base { };
int main() {
  Derived d; Base *b = &d;
  dynamic_cast<Derived*>(b); // Invalid
}
```   

> 要正确使用 dynamic_cast，在继承体系中的基类（即 Base）**必须至少有一个虚函数（通常是虚析构函数）**，否则 dynamic_cast 将无法工作。dynamic_cast 依赖于运行时类型信息（RTTI），而 **RTTI 只有在类包含虚函数时才会被启用。**

> 对于up_cast，对于dynamic和static都是成功的。  

```cpp
#include <iostream>  

class Base {
public:
    virtual ~Base() {} // 必须存在virtual function
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
```  

## Cast in Boost  


## References  
1. [stack overflow answer](https://stackoverflow.com/questions/28002/regular-cast-vs-static-cast-vs-dynamic-cast)  
2. [boost cast](https://boost.org/doc/libs/1_47_0/libs/conversion/cast.htm#Polymorphic_cast)

