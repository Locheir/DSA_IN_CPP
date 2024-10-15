#include <iostream>
using namespace std;

int power_bruteforce(int base, int pow) {
    if(pow == 1) {
        return base;
    }

    int res = base * power_bruteforce(base,pow-1);
    
    return res;
}

int power_logn(int base, int pow) {
    if (pow == 0) {
        return 1;
    }
    int halfPow = power_logn(base,pow/2);
    if (pow%2 != 0) {
        return base * halfPow * halfPow;
    } else {
        return halfPow * halfPow;
    }
}

int main() {

    cout << power_bruteforce(2,10)<< endl;
    cout << power_logn(2,10);
    return 0;
}