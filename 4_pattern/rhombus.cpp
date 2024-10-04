#include <iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++) {

        for (int j=num-i-1; j>0; j--){
            cout << " ";
        }

        for (int k=0; k<num; k++) {
            cout << "* ";
        }

        cout << endl;
    }
    
    return 0;
}