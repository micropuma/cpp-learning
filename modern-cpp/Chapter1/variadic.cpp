#include <iostream>

template <typename... T>
void printf(T... args) {
    std::cout << sizeof...(args) << "\n";
}

int main() {
    printf(1);
    printf();
    printf(1, "");

    return 0;
}