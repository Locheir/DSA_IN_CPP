#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col) {

    int n = board.size();

    // Horizontal :
    for (int j=0; j<n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    // Vertical :
    for (int i=0; i<n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Left Diagonal :
    for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Right Diagonal
    for (int i=row, j=col; i>=0 && j<n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

bool nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    bool result = false;
    if(row == n) {
        printBoard(board);
        return true;
    }

    for(int j=0; j<n; j++) {
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';
            result = nQueens(board, row+1);
            if (result == true) {
                break;
            }
            board[row][j] = '.';
        }
    }

    return result;
}

int main() {
    vector<vector<char>> board;
    int n = 5;

    for(int i=0; i<n; i++) {
        vector<char> temp;

        for(int j=0; j<n; j++) {
            temp.push_back('.');
        }

        board.push_back(temp);
    }

    nQueens(board, 0);

    return 0;
}