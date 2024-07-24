#include "student.h"
#include <string>

Student::Student() {
    name = "John Appleseed";
    state = "CA";
    age = 18;
}

Student::Student(std::string name, std::string state, int age) {
    this->name = name;
    this->state = state;
    this->age = age;
}

auto Student::getName() -> std::string {
    return this->name;
}

auto Student::getState() -> std::string {
    return this->state;
}

auto Student::getAge() -> int {
    return this->age;
}

auto Student::setName(std::string name) -> void {
    this->name = name;
}

auto Student::setState(std::string state) -> void {
    this->state = state;
}

auto Student::setAge(int age) -> void {
    if (age > 0) {
        this->age = age;
    }
}

int main() {
    std::string name;
    std::string state;
    int age;

    std::cin >> name >> state >> age;
    Student* stu = new Student(name , state, age);

    return 0;
}