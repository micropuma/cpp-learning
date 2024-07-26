#include <iostream>
#include <deque>

int main() {
    std::deque<int> q = { 1, 2, 3, 4, 5 };
    q.push_front(6);
    q.push_back(7);

    for (int i : q) {
        std::cout << i << std::endl;
    }
    return 0;
}