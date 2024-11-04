#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void leon_sort(vector<string> &word_bank) {
    sort(word_bank.begin(), word_bank.end());
    auto end = unique(word_bank.begin(), word_bank.end());
    word_bank.erase(end, word_bank.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    std::string s("LeonDou");
    std::string result = accumulate(s.cbegin(), s.cend(), string(""));

    vector<int> vec;
    fill_n(back_inserter(vec), 10, 1);

    cout << vec.size();
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    vec[vec.size()-1] = 3;
    replace(vec.begin(), vec.end(), 3, 4);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << "\n";
    cout << result;
    vector<string> string_bank;

    string_bank.push_back("Leon");
    string_bank.push_back("cc");
    string_bank.push_back("jdjdjdjdjjd");
    string_bank.push_back("jdjdjdjdjjd");
    string_bank.push_back("Laon");

    leon_sort(string_bank);
    stable_sort(string_bank.begin(), string_bank.end(), isShorter);
    for (const auto &string : string_bank) {
        cout << string << "\n";
    }

    return 0; 
}