#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>
using namespace std;

int main() {
    map<string, list<int>> wordLines;
    string line;
    int lineNumber = 0;

    // 模拟读取文件的每一行
    while (getline(cin, line)) {
        lineNumber++; // 处理行号

        stringstream ss(line);
        string word;

        // 分割每一行的单词
        while (ss >> word) {
            wordLines[word].push_back(lineNumber);  // 将行号添加到单词对应的list中
        }
    }

    // 打印单词及其出现的行号
    for (const auto &[word, lines] : wordLines) {
        cout << "Word: " << word << " appeared in lines: ";
        for (const int line : lines) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}

