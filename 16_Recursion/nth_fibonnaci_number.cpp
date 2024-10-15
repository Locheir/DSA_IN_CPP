#include <iostream>
using namespace std;

int nth_fibonnaci(int num) {
    if (num==1) {
        return 1;
    } 
    if (num == 0) {
        return 0;
    }
    int fib = nth_fibonnaci(num-1) + nth_fibonnaci(num-2);
    return fib;
}

int main() {

    cout << "Fibonnaci nth : " << nth_fibonnaci(8);

    return 0;
}