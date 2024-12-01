#include <iostream>
#include <string>

template <typename Named> struct Quack {
    void quack() {
        std::cout << "quacks:" << static_cast<Named*>(this)->name();
    }
};

template <typename Named> struct Snack {
    void snack() {
        std::cout << "snacks:" << static_cast<Named*>(this)->name();
    }
};

struct Duck : Quack<Duck>, Snack<Duck> {
    Duck(std::string name) : name_(std::move(name)) {}
    std::string name() { return name_; }
private:
    std::string name_;
};

int main() {
  // 测试 MullardDuck
  Duck mallard("Mallard");
  std::cout << "Testing MullardDuck:\n";
  mallard.quack();
  mallard.snack();

  return 0;
}