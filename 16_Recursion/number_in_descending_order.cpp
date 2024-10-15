#include <iostream>
using namespace std;

void print_descending(int num) {
    if (num == 1) {
        cout << 1 << endl;
        return;
    }
    cout << num << endl;
    print_descending(num-1);
    return;
}

int main() {
    print_descending(10);
    return 0;
}