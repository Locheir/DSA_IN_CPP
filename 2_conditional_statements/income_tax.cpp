#include<iostream>
using namespace std;

int main() {

    float income;

    cout << "Enter your Income : ";
    cin >> income;

    if (income <= 500000) {
        cout << "No Tax "<< endl;
        cout << "Income you will recieve : " << income << endl;
    } else if (income <= 1000000) {
        cout << "20% Tax : "<< endl;
        cout << "Income you will recieve : " << income - (0.20 * income) << endl;
    } else {
        cout << "30% Tax " << endl;
        cout << "Income you will recieve : " << income - (0.30 * income) << endl;
    }

    return 0;
}