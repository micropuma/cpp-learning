#include <iostream>
#include <vector>
#include <algorithm>

class Print {
public:
    void operator()(int x) const {
        std::cout << x << " ";
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), Print());

    return 0;
}