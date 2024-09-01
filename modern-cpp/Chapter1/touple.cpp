#include <iostream>
#include <tuple>

std::tuple<int, int, double> returnTuple() {
	return std::make_tuple(1,2,3.2);
}

int main() {
	auto [x, y, z] = returnTuple();
	std::cout << x << y << z;
	return 0;
}
