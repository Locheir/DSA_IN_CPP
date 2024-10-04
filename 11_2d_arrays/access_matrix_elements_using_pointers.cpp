#include <iostream>
using namespace std;

void func(int (*mat)[4], int i, int j) {

    // arr[i][j] == *(*(mat + i) + j)
    // We can access elements in a matrix also using pointers.
    cout << *(*(mat + i) + j) << endl;
}

int main() {
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int i=0, j=3;
    func(mat, i, j);

    return 0;
}