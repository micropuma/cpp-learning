#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal sound" << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow" << endl; }
};

int main() {
    Animal* animal1 = new Dog();  // 静态类型是 Animal*，动态类型是 Dog
    Animal* animal2 = new Cat();  // 静态类型是 Animal*，动态类型是 Cat

    animal1->speak();  // 输出 "Woof"，调用的是 Dog 的 speak
    animal2->speak();  // 输出 "Meow"，调用的是 Cat 的 speak

    delete animal1;
    delete animal2;

    return 0;
}
