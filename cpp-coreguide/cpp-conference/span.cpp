#include <iostream>
#include <span>
#include <vector>

void print(std::vector<int> const& vec) {
    for (auto const& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v{ 1, 2, 3, 4};

    std::vector<int> const w{v};
    std::span<int> const s{v};

    s[2] = 99;
    print(v);

    return 0;
}