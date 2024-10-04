#include <iostream>
using namespace std;

int main() {

    /* 
        Print this Pattern : 
        1
        2 3
        4 5 6
        7 8 9 10
    */

    int num;
    int count = 1;

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++) {
        for (int j=0; j<=i; j++) {
            cout << count << " ";
            count += 1;
        }
        cout << endl;
    }
    return 0;
}