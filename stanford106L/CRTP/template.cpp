#include <iostream>

template<typename T> 
class Amount {
public:
    double getValue() const { 
        return static_cast<T const&>(*this).getValue(); 
    }
};

class Const32 : public Amount<Const32> {
public:
    double getValue() const { return 32; }
};

class Invariant : public Amount<Invariant> {
public:
    explicit Invariant(double value) : _value(value) {}
    double getValue() const { return _value; }

private:
    double _value;
};

// 静态模板函数
template<typename T>
void print(Amount<T> const& amount)
{
    std::cout << amount.getValue() << '\n';
};

int main() {
    Const32 const32;
    Invariant inv(3);
    print(const32);
    print(inv);
}


