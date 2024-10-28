#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------\n";
}

bool isValid(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    if(row>=0 && row<n && col>=0 && col<n) {
        return true;
    }
    return false;
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    if (isValid(board, row-1, col-2)) {
        if(board[row][col] == 'K') {
            return false;
        }
    }

    if (isValid(board, row-2, col-1)) {
        if(board[row][col] == 'K') {
            return false;
        }
    }

    if (isValid(board, row-2, col+1)) {
        if(board[row][col] == 'K') {
            return false;
        }
    }

    if (isValid(board, row-1, col+2)) {
        if(board[row][col] == 'K') {
            return false;
        }
    }

    return true;
}

void nKnights(vector<vector<char>> board, int row, int col, int knights) {
    int n= board.size();
    if (knights==0) {
        printBoard(board);
        return;
    }

    if (row == n) {
        return;
    }

    if (col == n) {
        nKnights(board, row+1, 0, knights);
        return;
    }

    if(isSafe(board, row, col)) {
        board[row][col] = 'K';
        nKnights(board, row, col+1, knights-1);
        board[row][col] = '.';
    }

    nKnights(board, row, col+1, knights);
}

int main() {
    vector<vector<char>> board;
    int n = 3;

    for(int i=0; i<n; i++) {
        vector<char> temp;
        for(int j=0; j<n; j++) {
            temp.push_back('.');
        }
        board.push_back(temp);
    }

    nKnights(board, 0, 0, n);

    return 0;
}