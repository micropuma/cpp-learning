#include <iostream>
#include <memory>

class B;

class A {
public:
  std::weak_ptr<B> ptr_to_b;
  ~A() { std::cout << "All of A's resources deallocated" << std::endl; }
};

class B {
public:
  std::shared_ptr<A> ptr_to_a;
  ~B() { std::cout << "All of B's resources deallocated" << std::endl; }
};

int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->ptr_to_b = b;
  b->ptr_to_a = a;
  std::cout << b->ptr_to_a.use_count() << std::endl;
  std::cout << a->ptr_to_b.use_count();
  return 0;
}