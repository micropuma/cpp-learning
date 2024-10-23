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

class Shoe {
public:
    virtual void Show() = 0;
    virtual ~Shoe() {}
};


class NikeShoe : public Shoe{
public:  
    void Show() {
        std::cout << "This is Nike's Shoe" << std::endl;
    }
};