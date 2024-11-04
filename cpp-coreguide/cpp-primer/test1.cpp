#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec= {1, 2, 3, 4, 5};

	auto begin = vec.begin();
       	auto end = vec.end();

	while (begin != vec.end()) {
		++begin;
		begin = vec.insert(begin, 9);
		++begin;
	}
	
	return 0;
}
