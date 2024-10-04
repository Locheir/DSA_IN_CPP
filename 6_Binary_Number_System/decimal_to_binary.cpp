#include <iostream>
using namespace std;

int decimal_to_binary(int decNum) {
    int binNum = 0;
    int pow = 1;

    while(decNum > 0) {
        int temp = decNum%2;
        binNum += temp*pow;
        pow = pow*10;
        decNum = decNum/2;
    }

    return binNum;
}

int main() {
    int num;

    cout << "Enter a Decimal Number : ";
    cin >> num;

    cout << "Binary Number of "<< num << " is " << decimal_to_binary(num);

    return 0;
}