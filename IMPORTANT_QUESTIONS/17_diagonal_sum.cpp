#include <iostream>
using namespace std;

int diagonalSum(int mat[][3], int n){
    int sum = 0;
    for (int i=0, j=n-1; i<n; i++) {
        if (i==j) {
            sum += mat[i][i];
        } else {
            sum += mat[i][i] + mat[i][j];
        }
        j--;
    }

    return sum;
}

int main() {
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int mat2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Sum of both Diagonals : " <<diagonalSum(mat2, 3);

    return 0;
}