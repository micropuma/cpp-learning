#include "StrVector.h"
#include "Student.h"
#include <functional>
#include <iostream>
#include <map>

void defaultConstructor() {
  auto s = Student();
  std::cout << s.getName() << std::endl;
  std::cout << s.getState() << std::endl;
  std::cout << s.getAge() << std::endl;
}

void havenConstructor() {
  Student s = Student("Haven", "AR", 22);
  std::cout << s.getName() << std::endl;
  std::cout << s.getState() << std::endl;
  std::cout << s.getAge() << std::endl;
}

/// NOTE: uncomment to show the compiler error

// void failure() {
//   Student s = Student("Haven", "AR", 21);
//   s.name = Fabio;
// }

int main() {
  std::map<std::string, std::function<void()>> functionMap = {
      {"defaultConstructor", defaultConstructor},
      {"havenConstructor", havenConstructor},
      // {"inputFileStreamExample", inputFileStreamExample}
  };

  std::string inputFunctionName;
  while (true) {
    std::cout << "\nYou can run one of these functions:\n";
    for (const auto &pair : functionMap) {
      std::cout << pair.first << '\n';
    }
    std::cout << "\nEnter the name of the function you want to run (or 'exit' "
                 "to quit): ";
    std::getline(std::cin, inputFunctionName);

    if (inputFunctionName == "exit") {
      break;
    }

    auto iter = functionMap.find(inputFunctionName);
    if (iter != functionMap.end()) {
      std::cout << "\n###### OUTPUT ######\n";
      iter->second();
    } else {
      std::cout << "Function name not recognized. Please try again."
                << std::endl;
    }
  }

  return 0;
}