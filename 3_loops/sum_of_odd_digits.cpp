#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;

    cout << "Enter your Number : ";
    cin >> num;

    while (num > 0) {
        int temp = num % 10;
        if ((temp % 2) != 0)
            sum += temp;
        num = num/10;
    }

    cout << "Sum of Odd Digits : " << sum;

    return 0;
}