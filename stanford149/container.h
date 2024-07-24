#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

template <class T>
class Container {
private:
    T value;
public:
    Container(T val);
    T getValue();
};

template <class T>
Container<T>::Container(T val) {
    this->value = val;
}

template <typename T>
T Container<T>::getValue() {
    return value;
}

#endif // CONTAINER_H