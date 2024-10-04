#include <iostream>
#include <string>
using namespace std;

int main() {
    // In C++, strings are pre-defined classes.
    // we just need include the header files for string.

    string str = "hello";
    cout << str << endl;
    str = "yellow";
    cout << str << endl;

    string str_name;
    cout << "Enter your Name : ";
    getline(cin, str_name);
    cout << "Your Name is " << str_name;
    
    return 0;
}