#include <iostream>

// 接口，包括数值计算库
template<typename T>
class NumericalFunctions 
{
public:
    void scale(double multiplicator) {
        T& underlying = static_cast<T&>(*this);
        double result = underlying.getValue() * multiplicator;
        std::cout << "result: " << result << std::endl;
    }
};

class Sensitivity : public NumericalFunctions<Sensitivity> {
public:
    Sensitivity(double value) : _value(value) {}
    double getValue() { return _value; }

private:
    double _value; 
};

int main() {
    Sensitivity a = Sensitivity(0.4);
    a.scale(0.2);

    return 0;
}