#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {

    if (num==1){
        return false;
    }

    for (int i=2; i<=sqrt(num); i++){
        if (num%i==0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;

    cout << "Enter your Number : ";
    cin >> num;

    if (isPrime(num)) {
        cout << "Number "<< num <<" is Prime";
    } else {
        cout << "Number "<< num <<" is not Prime";
    }

    return 0;
}