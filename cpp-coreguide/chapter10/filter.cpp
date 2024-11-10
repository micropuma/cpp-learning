#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

int main() {
    vector<int> a{1,2,3,4,5,6,7};
    auto gen3 = [](auto &elem) {
        return elem > 3;
    };

    auto result = a | views::filter(gen3);
    for (const auto& res : result) {
        cout << res << " ";
    }
    return 0;
}