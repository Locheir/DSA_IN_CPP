#include <iostream>
using namespace std;

int main() {
    char ch1 = 'a';
    char ch2 = 'X';
    char ch3 = '%';
    char ch4 = '9';
    char ch5 = '\t';

    cout << "ch1 = " << ch1 << endl;
    cout << "ch2 = " << ch2 << endl;
    cout << "ch3 = " << ch3 << endl;
    cout << "ch4 = " << ch4 << endl;
    cout << "ch5 = " << ch5 << "tab space"<< endl;

    char ch = 'F';
    int pos = ch - 'A';
    cout << "Position of F from A : " << pos;

    return 0;
}