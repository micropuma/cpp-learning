#include <iostream>
#include <deque>
#include <vector>
#include <numeric>

// 检查容器操作使迭代器失效

using namespace std;

int main() {
    deque<int> q;
    vector<int> d;

    cout << "capacity of d: " << d.capacity() << "\n";

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    cout << "capacity of d: " << d.capacity() << "\n"; 

    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    cout << "capacity of d: " << d.capacity() << "\n"; 

    d.push_back(9);
    cout << "capacity of d: " << d.capacity() << "\n"; 

    int sum = accumulate(d.cbegin(), d.cend(), 0);
    cout << sum << "\n";

    vector<int>::iterator vec_it = d.begin();
    ++vec_it;
    d.push_back(6);
    cout << *vec_it;

    d.insert(vec_it, 10);
    cout << *vec_it;

    q.push_back(1);
    deque<int>::iterator it = q.begin();

    q.push_back(2);
    cout << *it;
    q.pop_back();
    cout << *it;

    return 0;
}
