#include <iostream>
using namespace std;

int count_set_bit(int num) {
    int count = 0;
    while(num > 0) {
        int lastDigit= num&1;
        count += lastDigit;
        num = num>>1;
    }
    return count;
}

int main() {
    
    cout << count_set_bit(7);

    return 0;
}