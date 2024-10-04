#include <iostream>
using namespace std;

// 2022. Convert 1D Array Into 2D Array

int convert(int arr[], int size, int n, int m) {

    if(m*n != size) {
        int temp[0][0];
        cout << "result : " << *temp << endl;
        return -1;
    } 
    int index = 0;
    int res[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)  {
            res[i][j] = arr[index];
            index++;
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    
    cout << convert(arr, size, 2, 2);

    return 0;
}