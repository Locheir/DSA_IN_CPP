#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "Enter your Age ";
    cin >> age;

    bool isAdult = (age >= 18) ? true : false;

    if (isAdult) {
        cout << "You are eligible to vote";
    } else {
        cout << "You are not eligible to vote";
    }
}