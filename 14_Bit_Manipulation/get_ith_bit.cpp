#include <iostream>
using namespace std;

int get_ith_bit(int num, int pos) {
    int bitmask = 1 << pos;
    if (!(num & bitmask)) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int num;
    int pos;
    
    cout << "Enter a Number : ";
    cin >> num;

    cout << "Enter no of bit you want : ";
    cin >> pos;

    cout << get_ith_bit(num, pos);

    return 0;
}