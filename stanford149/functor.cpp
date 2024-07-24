#include <iostream>

class Accumulator {
private:
    int sum;
public:
    Accumulator() : sum(0) {}

    void operator()(int x) {
        sum += x;
    }

    int getSum() { return sum; }
};

int main() {
    Accumulator acc;
    acc(10);
    std::cout << acc.getSum() << std::endl;
    acc(20);
    std::cout << acc.getSum() << std::endl;

    return 0;
}