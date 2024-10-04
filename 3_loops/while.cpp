#include <iostream>
using namespace std;

int main() {
    int num;
    int i = 1;

    cout << "Enter the nth Number : ";
    cin >> num;
    
    while(i<=num) {
        cout << i << endl;
        i++;
    }
}