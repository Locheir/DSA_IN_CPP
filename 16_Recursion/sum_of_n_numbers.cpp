#include <iostream>
using namespace std;

int sum_of_n_numbers(int num) {
    if (num == 1) {
        return 1;
    }
    int sum = num + sum_of_n_numbers(num-1);
    return sum;
}

int main() {

    cout << "Sum of n Numbers : " << sum_of_n_numbers(5);
    return 0;
}