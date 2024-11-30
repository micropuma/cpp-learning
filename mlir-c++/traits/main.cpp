#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;

template<class inputIterator, class T>
inputIterator find(inputIterator first, inputIterator last, const T& value) {
    while (first != last && *first != value) {
        ++first;
    }
    return last;
}   // namespace mlir

int main() {
    const int arraySize = 7;
    int ia[arraySize] = {1, 2, 3, 4, 1024, 1034, 3092};

    vector<int> ivect(ia, ia+arraySize);
    list<int> ilist(ia, ia+arraySize);
    deque<int> ideque(ia, ia+arraySize);

    deque<int>::iterator it = find(ideque.begin(), ideque.end(), 1024);
    if (it != ideque.end()) {
        cout << "find 1024 in ideque" << endl;
    }

    return 0;
}
