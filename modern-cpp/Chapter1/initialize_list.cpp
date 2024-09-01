#include <initializer_list>
#include <iostream>
#include <vector>

class MagicFoo {
public:
    MagicFoo(std::initializer_list<int> array) {
        for (auto it = array.begin(); it != array.end(); ++it) {
            _array.push_back(*it);
        }
    }

    void printVec() {
        for (auto it = _array.cbegin(); it != _array.cend(); ++it) {
            std::cout << *it << " " ;
        }
    }
private:
    std::vector<int> _array;
};

int main() {
    MagicFoo foo = MagicFoo{1,2,3,4};
    foo.printVec();

    return 0;
}

