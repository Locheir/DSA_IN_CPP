#include <iostream>
using namespace std;

// Recursion : when a function repeatedly calls itself.
int fact(int);

int fact(int num) {
    if (num == 1) {
        return 1;
    }
    int factorial = num * fact(num-1);
    return factorial;
}

int main() {
    int res = fact(10);
    cout << "Factorial : " << res;

    return 0;
}