#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "This is a string";

    cout << str.length() << endl;
    cout << str[2] << endl;
    cout << str.at(2) << endl;
    cout << str.substr(3,9) << endl;
    cout << str.find("c");
    return 0;
}