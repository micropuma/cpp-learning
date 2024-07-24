#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    const std::vector<int>& bad_ref = vec1;
    bad_ref.push_back(1);
    return 0;
}