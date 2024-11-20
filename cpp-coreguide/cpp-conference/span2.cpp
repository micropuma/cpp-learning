#include <iostream>
#include <span>
#include <vector>
#include <algorithm>

void print(std::span<int const> vec) {
    for (auto const& elem : vec) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

int main() 
{ 
    std::vector<int> vec{ 1, -3, 27, 42, 4, -8, 22, 42, 37, 4, 18, 9 }; 
    print( vec ); 
    // Prints ( 1 -3 27 42 4 -8 22 42 37 4 18 9 )
    // Determining the maximum element in the range 'vec' 
    auto const pos = std::max_element( begin(vec), end(vec) );
    // Removing all maximum elements 
    vec.erase( std::remove( begin(vec), end(vec), *pos ), end(vec) );
    print( vec );
    // Prints ( 1 -3 27 4 -8 22 42 37 18 9 )
    return EXIT_SUCCESS; 
 }
