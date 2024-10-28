#include <iostream>
using namespace std;

void printSudoku(int arr[][9]) {
    for(int i=0; i<9; i++){
        for (int j=0; j<9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int arr[][9], int row, int col, int digit) {
    for(int i=0; i<9; i++){
        if(arr[row][i] == digit) {
            return false;
        }
    }

    for(int j=0; j<9; j++) {
        if (arr[j][col] == digit) {
            return false;
        }
    }

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i<=startRow+2; i++) {
        for(int j=startCol; j<=startCol+2; j++) {
            if(arr[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int arr[][9], int row, int col) {
    if(row == 9) {
        printSudoku(arr);
        return true;
    }

    int nextRow = row;
    int nextCol = col+1;
    if (col+1 == 9) {
        nextRow = row+1;
        nextCol = 0;
    }

    if(arr[row][col] != 0) {
        return sudokuSolver(arr, nextRow, nextCol);
    }

    for(int digit=1; digit<=9; digit++) {
        if(isSafe(arr, row, col, digit)) {
            arr[row][col] = digit;
            if(sudokuSolver(arr, nextRow, nextCol)) {
                return true;
            }
            arr[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int sudoku[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    cout << sudokuSolver(sudoku, 0, 0);
    return 0;
}