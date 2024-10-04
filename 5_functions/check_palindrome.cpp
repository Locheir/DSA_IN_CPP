#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int copy = num;
    int rev = 0;

    while (copy > 0) {
        int temp = copy % 10;
        rev = rev*10 + temp;
        copy = copy / 10;
    }

    if (num==rev) { 
        return true;
    } else {
        return false;
    }
}

int main() {
    int num;

    cout << "Enter a Number : ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a Palindrome Number";
    } else {
        cout << num << " is not a Palindrome Number";
    }

    return 0;
}