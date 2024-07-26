#include <iostream>
#include <vector>

template <typename InputIt, typename UniPred> 
int count_occurrences(InputIt start, InputIt end, UniPred pred) {
    int count = 0;
    for (auto iter = start; iter != end; ++iter) {
        if(pred(*iter)) {
            std::cout << *iter << std::endl;
            ++count;
        }
    }
    
    return count;
}

int main() {
    int limit = 5;
    auto isMoreThan = [limit](int n) -> bool {
        return n > limit;
    };

    std::vector<int> nums = {3, 5, 6, 7, 9, 13};
    count_occurrences(nums.begin(), nums.end(), isMoreThan);     

    return 0; 
}