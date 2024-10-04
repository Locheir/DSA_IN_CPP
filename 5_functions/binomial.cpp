#include <iostream>
using namespace std;

int fact(int num) {
    int result=1;

    for (int i=1; i<=num; i++) {
        result = result * i;
    }

    return result;
}

int binomial(int n, int r) {
    return fact(n)/(fact(r)*fact(n-r));
}

int main() {
    int n;
    int r;

    cout << "Enter value of n : ";
    cin >> n;

    cout << "Enter value of r : ";
    cin >> r;

    cout << "Binomial = " << binomial(n, r);

    return 0;
}