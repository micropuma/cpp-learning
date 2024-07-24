#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>

class Student {
private:
    using String = std::string;
    String name;
    String state;
    int age;

public:
    Student();
    ~Student();
    Student(std::string name, std::string state, int age);
    String getName();
    String getState();
    int getAge();

    void setName(String name);
    void setState(String state);
    void setAge(int age);
};

#endif