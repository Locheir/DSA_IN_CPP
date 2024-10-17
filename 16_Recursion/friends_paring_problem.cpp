#include <iostream>
using namespace std;

int friends_paring(int num) {
    if (num == 1 | num == 2) {
        return num;
    }
    return friends_paring(num-1) + (num-1)*friends_paring(num-2);
}

int main() {
    cout << friends_paring(4) << endl;
    return 0;
}