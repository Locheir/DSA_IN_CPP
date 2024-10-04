#include <iostream>
using namespace std;

int main() {

    /*
        Print this Pattern :
        * * * * 
        * * *
        * *
        *  
    */

    int num;

    cout << "Enter No of Rows : ";
    cin >> num;

    for (int i=0; i<=num; i++){
        for (int j=num-i; j>0; j--){
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}