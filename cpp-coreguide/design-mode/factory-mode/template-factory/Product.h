#pragma once

#include <iostream>

class Clothe {
public:
    virtual void Show() = 0;
    virtual ~Clothe() {}
};


class NikeClothe : public Clothe {
public:  
    void Show() {
        std::cout << "This is Nike's clothe" << std::endl;
    }
};

class adidasClothe: public Clothe {
public:  
    void Show() {
        std::cout << "This is Adidas's clothe" << std::endl;
    }
};

