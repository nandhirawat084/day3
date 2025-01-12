#include <iostream>
using namespace std;

string reverseString(string str) {
    if (str.empty()) {
        return str;
    }
    return reverseString(str.substr(1)) + str[0];
}

int main() {
    string str = "Hello, world!";
    cout << "Original string:" << str <<endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}
