#include <iostream>
#include <string>
#include <utility>

// 这个的写法非常的fancy！！！

// 这个template的写法就十分像interface了，或者说是trait。
// 定义功能模块 A: 可以呱呱叫的鸭子
template <typename Derived>
struct Quackable {
  void quack() {
    std::cout << static_cast<Derived*>(this)->name() << " is quacking: Quack! Quack!" << std::endl;
  }
};

// 定义功能模块 B: 可以游泳的鸭子
template <typename Derived>
struct Swimable {
  void swim() {
    std::cout << static_cast<Derived*>(this)->name() << " is swimming in the pond!" << std::endl;
  }
};

// 定义功能模块 C: 可以飞翔的鸭子
template <typename Derived>
struct Flyable {
  void fly() {
    std::cout << static_cast<Derived*>(this)->name() << " is flying high in the sky!" << std::endl;
  }
};

// 定义 Duck 模板
// Duck模版被传入一个或多个功能模块，这些功能模块都是CRTP模式的基类
template <template <typename...> class... Bases>
struct Duck : Bases<Duck<Bases...>>... {
  // 用传入的模版初始化基类
  Duck(std::string name)
      : name_{std::move(name)}
      , Bases<Duck<Bases...>>{*this}... {
  }

  std::string name() const {
    return name_;
  }

private:
  std::string name_;
};

// 使用 Duck 定义不同类型的鸭子
using WildDuck = Duck<Quackable, Swimable, Flyable>; // 野鸭：会叫、会游泳、会飞
using RubberDuck = Duck<Quackable>;                 // 橡皮鸭：只会叫
using WoodenDuck = Duck<>;                          // 木头鸭：什么都不会

int main() {
  WildDuck wild_duck{"Wild Duck"};
  RubberDuck rubber_duck{"Rubber Duck"};
  WoodenDuck wooden_duck{"Wooden Duck"};

  // WildDuck 的行为
  wild_duck.quack();
  wild_duck.swim();
  wild_duck.fly();

  // RubberDuck 的行为
  rubber_duck.quack();

  std::cout << wooden_duck.name() << " is just a decoration!" << std::endl;

  return 0;
}
