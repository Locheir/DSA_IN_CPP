#include <iostream>
using namespace std;

int main() {

    int num;
    int sum = 0;

    cout << "Enter your Number : ";
    cin >> num;

    while (num > 0) {
        int temp = num % 10;
        sum += temp;
        num = num/10;
    }

    cout << "Sum of Digits : " << sum;

    return 0;
}