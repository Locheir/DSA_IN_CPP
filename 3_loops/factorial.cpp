#include <iostream>
using namespace std;

int main() {
    int num;
    int fact = 1;
    cout << "Enter Number : ";
    cin >> num;

    for(int i=2;i<=num;i++) {
        fact = fact * i;
    }

    cout << "Factorial of " << num << " is " << fact;
    return 0;
}