#include<iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Enter 1st Number : ";
    cin >> a;

    cout << "Enter 2nd Number : ";
    cin >> b;

    if (a > b) {
        cout << a << " is the greatest.";
    } else {
        cout << b << " is the greatest.";
    }

    return 0;
}