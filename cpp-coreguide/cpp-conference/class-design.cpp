#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class MyString {
private:
    string str;
    string str2;
    int value;

public:
    MyString(const string& s, const string& s2, int v) : str(s), str2(s2), value(v) {
        cout << "Constructor called." << endl;
    }

    MyString(const MyString& ms) : str(ms.str), str2(ms.str2), value(ms.value) {
        cout << "Copy constructor called." << endl;
    }

    MyString(MyString&& ms) : str(move(ms.str)), str2(move(ms.str2)), value(ms.value) {
        cout << "Move constructor called." << endl;
    }

    friend ostream& operator<<(ostream& os, const MyString& ms) {
        os << ms.str << " " << ms.str2 << " " << ms.value;
        return os;
    }
};

int main() {
    vector<MyString> v1; 
    v1.push_back(MyString("Hello", "World", 42));
    cout << v1[0] << endl;

    return 0;
}