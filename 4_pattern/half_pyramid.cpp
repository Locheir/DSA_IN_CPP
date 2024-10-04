#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern :
        1 
        1 2  
        1 2 3 
        1 2 3 4 
    */

    int num;

    cout << "Enter No of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++){
        for (int j=0; j<=i; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }

    return 0;
}