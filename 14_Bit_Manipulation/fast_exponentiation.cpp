#include <iostream>
using namespace std;

int fast_exponentiation(int num, int expo) {
    int ans = 1;
    int x = num;
    while (expo > 0) {
        if (expo & 1) {
            ans = ans*x;
        }
        x=x*x;
        expo = expo >> 1;
    }
    return ans;
}

int main() {

    cout << fast_exponentiation(2, 10);

    return 0;
}