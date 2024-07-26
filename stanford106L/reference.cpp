#include <iostream>
#include <vector>

void shift(std::vector<std::pair<int, int>>& nums) {
    for (auto& [num1, num2] : nums) {
        num1++;
        num2++;
    }
}

int main() {
    std::vector<std::pair<int, int>> nums = {{1,2}, {3,4}, {5,6}};
    std::cout << "====== before shift =====\n";
    for (const auto& [num1, num2] : nums) {
        std::cout << num1 << " " << num2 << std::endl;
    }

    shift(nums);

    std::cout << "====== after shift =====\n";
    for (const auto& [num1, num2] : nums) {
        std::cout << num1 << " " << num2 << std::endl;
    }

    return 0; 
}