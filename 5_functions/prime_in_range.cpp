#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }

    for (int i=2; i<=sqrt(num); i++) {
        if (num%i==0) {
            return false;
        }
    }

    return true;
}

void allPrime(int n) {
    for (int i=2; i<=n; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
}

int main() {
    int num;

    cout << "Enter the range : ";
    cin >> num;

    allPrime(num);

    return 0;
}