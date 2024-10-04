#include <iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter no of Rows : ";
    cin >> num;

    for (int i=0; i<num; i++){
        // Space 
        for (int j=num-i-1; j>0; j--){
            cout << "  ";
        }

        for (int k=i+1; k>0; k--){
            cout << k << " ";
        }

        for (int l=2; l<=i+1; l++){
            cout << l << " ";
        }

        cout << endl;
    }

    return 0;
}