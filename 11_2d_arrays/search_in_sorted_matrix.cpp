#include <iostream>
using namespace std;

bool search_sorted_matrix_brute_force(int mat[][4], int n, int m, int key) {
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(key == mat[i][j]){
                cout << "Found at cell : " << i << "," << j << endl;
                return true;
            }
        }
    }

    return false;
}

bool search_sorted_matrix_binary_search(int mat[][4], int n, int m, int key) {
    for(int i=0; i<n; i++) {
        int start = 0;
        int end = m-1;
        while(start <= end) {
            int mid = (start+end)/2;

            if (key==mat[i][mid]) {
                cout << "Found at cell : " << i << "," << mid << endl;
                return true;
            }
            if (key < mat[i][mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    return false;
}

bool search_sorted_matrix_most_optimal(int mat[][4], int n, int m, int key) {
    int i = 0, j = m-1;

    while( i<n && j>=0) {
        if(mat[i][j] == key) {
            cout << "Found at cell : " << i << "," << j << endl;
            return true;
        } else if (mat[i][j] > key) {
            //left 
            j--;
        } else {
            //down
            i++;
        }
    }
    cout << "Key not found!"<< endl;
    return false;
}

int main() {
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int key = 2;
    cout << "Element is present : " << search_sorted_matrix_most_optimal(mat, 4, 4, key);

    return 0;
}