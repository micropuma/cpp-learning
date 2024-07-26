#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<int, int> reference {{1,2}, {3,4}, {5,6}};
    for (auto iter = reference.begin(); iter != reference.end(); ++iter) {
        const auto& [key, value] = *iter;
        std::cout << "key: " << key << " " << "value: " << value << std::endl;  
    }

    return 0;
}