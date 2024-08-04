#include <iostream>
#include <vector>

class HumanGenome {
private:
    std::vector<char> data;
public:
    HumanGenome() = default;

    HumanGenome(size_t size) : data(size) {
        std::fill(data.begin(), data.end(), 'A');
    }

    // move semantics
    HumanGenome(HumanGenome&& other) noexcept : data(std::move(other.data)) {
        std::cout << "HumanGenome moved into stage." << std::endl;
    }
}