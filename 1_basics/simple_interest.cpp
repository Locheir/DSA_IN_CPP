#include<iostream>
using namespace std;

int main() {
    float principal;
    float rate;
    float time;

    cout << "Enter the Principal Amount : ";
    cin >> principal;

    cout << "Enter the Rate of Interest : ";
    cin >> rate;

    cout << "Enter the Time Period in Years : ";
    cin >> time;

    float si = (principal * rate * time) / 100;

    cout << "The Simple Interest is : " << si;
    return 0 ;
}