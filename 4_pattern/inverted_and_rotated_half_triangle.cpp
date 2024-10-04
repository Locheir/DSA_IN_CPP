#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern : 
              *
            * *
          * * *
        * * * *
    */

    int num;

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++) {
        for (int j=0; j<num-i-1; j++) {
            cout << "  ";
        }
        for (int j=0; j<=i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}