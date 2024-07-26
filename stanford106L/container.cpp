#include "container.h"

int main() {
    Container<int> con(30);
    std::cout << con.getValue() << std::endl;
    return 0;
}
