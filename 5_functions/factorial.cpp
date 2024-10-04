#include <iostream>
using namespace std;

int fact(int num) {
    int result = 1;

    for (int i=1; i<=num; i++){
        result = result*i;
    }

    return result;
}

int main() {
    int num;

    cout << "Enter a Number : ";
    cin >> num;

    cout << "Factorial of " << num << " is " << fact(num);

    return 0;
}