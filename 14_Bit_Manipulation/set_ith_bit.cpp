#include <iostream>
using namespace std;

int set_ith_bit(int num, int pos) {
    int bitmask = 1 << pos;
    return (num | bitmask);
}

int main() {

    cout << set_ith_bit(6, 3);

    return 0;
}