#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a+b;
}

double sum(double a, double b) {
    return a+b;
}

int sum(int a, int b, int c) {
    return a+b+c;
}

int main() {

    cout << "Sum of two int : " << sum(2,3) << endl;
    cout << "Sum of two float : " << sum(2.3, 4.3) << endl;
    cout << "Sum of three int : " << sum(7,2,3) << endl;

    return 0;
}