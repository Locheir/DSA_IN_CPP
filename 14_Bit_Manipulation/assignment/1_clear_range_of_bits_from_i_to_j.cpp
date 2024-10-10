#include <iostream>
using namespace std;

int clear_range_of_bits(int num, int i, int j) {
    int a = (~0) << (j+1);
    int b = (1 << i) - 1;

    int bitmask = a | b;
    return num & bitmask;
}

int main() {

    cout << clear_range_of_bits(31, 1, 3);

    return 0;
}