#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern : 
              *
            * * *
          * * * * *
        * * * * * * *
          * * * * *
            * * *
              *
    */

    int num; 

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++) {

        // Printing Space
        for (int j=0; j<num-i-1; j++) {
            cout << "  ";
        }

        // Printing Pattern
        
        for (int k=0; k<(2*i)+1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i=num; i>0; i--) {

        // Printing Space
        for (int j=num-i+1; j>0; j--) {
            cout << "  ";
        }

        // Printing Pattern
        
        for (int k=(2*(i-1))-1; k>0; k--)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}