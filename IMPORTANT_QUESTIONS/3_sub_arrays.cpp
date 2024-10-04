#include <iostream>
using namespace std;

// Number of sub-arrays in an array of n lenght : 
// number of sub-arrays = n*(n+1)/2

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++){
            for (int k=i; k<=j; k++){
                cout << arr[k] << " ";
            }
            cout << " , ";
        }
        cout << endl;
    }

    return 0;
}