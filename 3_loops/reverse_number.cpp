#include <iostream>
using namespace std;

int main() {
    int num;
    int rev = 0;

    cout << "Enter your Number : ";
    cin >> num;

    while (num > 0) {
        int temp = num % 10;
        rev = rev*10 + temp;
        num = num / 10;
    }

    cout << "Reverse Number : " << rev;

    return 0;
}