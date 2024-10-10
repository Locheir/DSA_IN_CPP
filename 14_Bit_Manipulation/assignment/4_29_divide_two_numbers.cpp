#include <iostream>
using namespace std;

int divideNumber_bruteForce(int divident, int divisor) {
    int sum = 0, count = 0;
    while(sum + divisor <= divident) {
        count++;
        sum += divisor;
    }
    return count;
}   

int main() {
    

    return 0;
}