#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------\n";
}

bool isValid(vector<vector<char>> board, int row, int col) {
    if (row>=0 && row<board.size() && col>=0 && col<board.size()) {
        return true;
    }
    return false;
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    if (isValid(board, row-2, col-1) && board[row-2][col-1] == 'K') {
        return false;
    }

    if (isValid(board, row-1, col-2) && board[row-1][col-2] == 'K') {
        return false;
    }

    if (isValid(board, row-2, col+1) && board[row-2][col+1] == 'K') {
        return false;
    }

    if (isValid(board, row-1, col+2) && board[row-1][col+2] == 'K') {
        return false;
    }

    return true; // Return true if no knights threaten this position
}

void nKnights(vector<vector<char>> board, int row, int col, int knights) {
    if (knights == 0) {
        printBoard(board);
        return; // Return after printing a solution
    }

    if (row == board.size()) {
        return; // Return if row index exceeds board size
    }

    if (col == board.size()) {
        nKnights(board, row+1, 0, knights); // Move to the next row
        return;
    }

    // Place a knight if it's safe
    if (isSafe(board, row, col)) {
        board[row][col] = 'K'; // Place knight (represented by 'Q')
        nKnights(board, row, col+1, knights-1); // Recur for next cell
        board[row][col] = '.'; // Backtrack
    }

    nKnights(board, row, col+1, knights); // Recur without placing a knight
}

int main() {
    int n = 2; // Size of the board and number of knights to place
    vector<vector<char>> board(n, vector<char>(n, '.')); // Initialize board with '.'

    nKnights(board, 0, 0, n); // Start placing knights from the top-left corner

    return 0;
}
