#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> v1;
    v1.reserve(4);

    string s = "Hello";

    cout << s << endl;

    v1.push_back(move(s));

    cout << s << endl;

    cout << v1[0] << endl;
    cout << v1[5] << endl;

    return 0;
}