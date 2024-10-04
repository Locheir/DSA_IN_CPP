#include <iostream>
using namespace std;

int main() {
    int n=2, m=3;

    int arr[n][m] = {
        {4, 7, -10},
        {5, 11, 0}
    };

    int arr2[m][n];

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            arr2[j][i] = arr[i][j]; 
        }
    }

    for(int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}