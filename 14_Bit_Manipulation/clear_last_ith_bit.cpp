#include <iostream>
using namespace std;

void clear_last_ith_bit(int num, int pos) {
    int bitmask = ((~0)<<pos);
    num = num & bitmask;

    cout << num;
}

int main() {

    clear_last_ith_bit(15, 2);
    return 0;
}