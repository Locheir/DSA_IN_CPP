#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern :
        1 1 1 1
        2 2 2 2 
        3 3 3 3 
        4 4 4 4 
    */

    int num;

    cout << "Enter a Number : ";
    cin >> num;

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cout << i+1 << " ";
        }
        cout << endl;
    }

    return 0;
}