#include <iostream>
using namespace std;

int clear_ith_bit(int num, int pos) {
    int bitmask = ~(1<<pos);
    return num & bitmask;
}

int main() {
    cout << clear_ith_bit(6,1);

    return 0;
}