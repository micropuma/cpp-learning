#include <iostream>

class Animals {
public:
    void hello() {
        std::cout << "i am an animales\n";
    }
};

class Dogs : Animals {
public:
    void hello() {
        std::cout << "i am dogs\n";
    }
};

void func(Animals* animal) {
    animal->hello();
}

int main() {
    Animals* animale = new Animals;
    Dogs* dog = new Dogs;

    func(animale);
    func(dog);
}