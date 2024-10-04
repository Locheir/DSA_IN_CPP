#include<iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter your Number : ";
    cin >> num;

    if (num%2==0) {
        cout << num << " is an Even Number";
    } else {
        cout << num << " is an Odd Number";
    }

    return 0;
}