#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("hello.txt");
    if (ofs.is_open()) {
        ofs << "Hello CS106L!" << "\n";
    }

    ofs.close();
    ofs << "This will not be written!" << "\n";

    ofs.open("hello.txt", std::ios::app);
    ofs << "This will though!";

    ofs.close();

    return 0;
}