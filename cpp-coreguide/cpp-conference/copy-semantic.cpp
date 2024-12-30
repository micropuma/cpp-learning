#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> v1;

    // 检查初始时 vector 的容量
    cout << "The initial capacity is: " << v1.capacity() << endl;

    // 预先为 vector 分配空间
    v1.reserve(4);

    // 检查 reserve 后的容量
    cout << "The capacity after reserve is: " << v1.capacity() << endl;

    // 创建字符串 s，并打印它的地址
    string s = "Hello";
    cout << "Address of s before push_back: " << &s << endl;

    // 打印 vector 内部存储元素的地址，并观察是否发生了拷贝构造或移动构造
    cout << "Address of element in vector before push_back: ";
    if (!v1.empty()) {
        cout << &v1[0] << endl;
    } else {
        cout << "Vector is empty." << endl;
    }

    // 使用拷贝构造或移动构造插入元素
    v1.push_back(s);  // 拷贝构造
    cout << "Address of s after push_back: " << &s << endl;

    cout << "Address of element in vector after push_back: " << &v1[0] << endl;

    // 使用字符串字面量插入并打印地址
    cout << "Address of the literal \"Hello\" before push_back: " << static_cast<void*>(const_cast<char*>("Hello")) << endl;
    v1.push_back("Hello");  // 插入字符串字面量
    cout << "Address of the literal \"Hello\" after push_back: " << static_cast<void*>(const_cast<char*>("Hello")) << endl;

    // 检查向 vector 插入的元素地址
    cout << "Address of element in vector after second push_back: " << &v1[1] << endl;

    return 0;
}
