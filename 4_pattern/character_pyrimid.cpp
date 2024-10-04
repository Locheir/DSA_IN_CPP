#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern : 
            A
            B C
            D E F
            G H I J
    */

    int num;
    int count = 65;

    cout << "Enter No of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++){
        for (int j=0; j<=i; j++){
            cout << (char)count << " ";
            count += 1;
        }
        cout << endl;
    }

    return 0;
}