#include <iostream>
using namespace std;

void printArr(int mat[][3], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printArr(arr, 3, 3);

    for(int i=0; i<3; i++) {
        for(int j=i; j<3; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printArr(arr, 3, 3);

    for( int i=0; i<3; i++) {
        int start = 0;
        int end = 2;
        while(start <= end) {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }

    printArr(arr, 3, 3);

    return 0;
}