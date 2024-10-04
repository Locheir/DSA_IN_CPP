#include <iostream>
using namespace std;

int sum_of_digit(int num) {
    int sum = 0;

    while (num > 0) { 
        sum += num % 10;
        num = num/10;
    }

    return sum;
}

int main() {
    int num;

    cout << "Enter a Number : ";
    cin >> num;

    cout << "Sum of digits of " << num << " is " << sum_of_digit(num);
    
    return 0;
}