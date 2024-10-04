#include <iostream>
using namespace std;

int main() {
    
    int num;

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0 ;i<num; i++) {

        // Print Pattern
        for (int j=i; j>=0; j--) {
            cout << "* ";
        }

        // Print Space 
        for (int k=0; k<(num-i-1)*2; k++){
            cout << "  ";
        }

        // Print Pattern
        for (int j=i; j>=0; j--) {
            cout << "* ";
        }

        // Next Line
        cout << endl;
    }

    for (int i=0; i<num*2; i++) {

        for (int j=0; j<num-i; j++) {
            cout << "* ";
        }

        for(int k=0; k<i*2; k++) {
            cout << "  ";
        }

        for (int j=0; j<num-i; j++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}