#include <iostream>
using namespace std;



int binary_to_decimal(int bitNum) {
    int decNum = 0;
    int pow = 1;

    while(bitNum > 0) {
        int lastDig = bitNum%10;
        decNum += lastDig * pow;
        pow = pow*2;
        bitNum = bitNum/10;
    }

    return decNum;
}

int main() {
    int num;

    cout << "Enter a Binary Number : ";
    cin >> num;

    cout << "Decimal Number of " << num << " is " << binary_to_decimal(num);

    return 0;
}