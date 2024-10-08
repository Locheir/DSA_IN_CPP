#include <iostream>
using namespace std;

// ODD NUMBER -> right most bit is 1
// EVEN NUMBER -> right most bit is 0

// Bit masks : these are used to access 
//             specific bits in a byte 
//             of data.

int main() {
    int num;

    cout << "Enter a Number : ";
    cin >> num;

    if(num & 1) {
        cout << "Number " << num << " is Odd.";
    } else {
        cout << "Number " << num << " is Even.";
    }

    return 0;
}