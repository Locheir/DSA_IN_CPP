#include <iostream>
using namespace std;

bool check_pow_of_2(int num) {
    if (!(num & (num-1))){
        return true;
    } else {
        return false;
    }
}

int main() {

    cout << check_pow_of_2(4) << endl;
    cout << check_pow_of_2(16) << endl;
    cout << check_pow_of_2(7) << endl;

    return 0;
}