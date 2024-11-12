#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> mp({{"leon", 1}, {"dou", 2}});
    cout << mp["leon"];
    mp["hello"];
    for (const auto [key,value] : mp) {
        cout << key << " " << value;
    }

    return 0;
}