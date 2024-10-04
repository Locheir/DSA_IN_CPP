#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    bool isprime = true;

    cout << "Enter a Number : ";
    cin >> num;

    for (int i=2;i<=sqrt(num);i++){
        if (num%i==0) {
            isprime = false;
            break;
        }
    }

    if (isprime) {
        cout << num << " is a prime number";
    } else {
        cout << num << " is a composite number";
    }
}