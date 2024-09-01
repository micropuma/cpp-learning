#include <iostream>

template <typename Value, typename... Ts> 
void printf(Value t1, Ts... t2) {
    std::cout << t1 << "\n";
    if constexpr (sizeof...(t) > 0)
        printf(t2...);
    else 
        std::cout << "nothing to print\n";
}

int main() {
    printf(1, 2, "3", "");
    return 0;
}