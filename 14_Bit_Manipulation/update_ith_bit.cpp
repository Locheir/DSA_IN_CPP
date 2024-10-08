#include <iostream>
using namespace std;

void update_ith_bit(int num, int pos, int val){
    num = num & ~(1<<pos);

    num = num | (val<<pos);
    cout << num << endl;
}

int main() {
    update_ith_bit(7, 3, 1);

    return 0;
}