#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVis(vector<vector<bool>> vis) {
    int n = vis.size();
    vis[n-1][n-1] = true;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}

void solveMazeUtil(int maze[][4], int x, int y, string sol, int N, vector<vector<bool>> vis) {
    if(x==N-1 && y==N-1 && maze[x][y] == 1) {
        printVis(vis);
        cout << sol << "\n";
        return;
    }

    // down :
    if (x+1 < N && !vis[x+1][y] &&maze[x+1][y] == 1 ) {
        vis[x][y] = true;
        solveMazeUtil(maze, x+1, y, sol+"D", N, vis);
        vis[x][y] = false;
    }

    // left :
    if (y-1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y-1, sol+"L", N, vis);
        vis[x][y] = false;
    }

    // right :
    if (y+1 < N && !vis[x][y+1] && maze[x][y+1] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x, y+1, sol+"R", N, vis);
        vis[x][y] = false;
    }

    // up :
    if (x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1) {
        vis[x][y] = true;
        solveMazeUtil(maze, x-1, y, sol+"U", N, vis);
        vis[x][y] = false;
    }
}

void solveMaze(int maze[][4], int N) {
    string sol = "";
    vector<vector<bool>> vis(N, vector<bool> (N, false));

    if (maze[0][0] == 1) {
        solveMazeUtil(maze, 0, 0, sol, N, vis);
    }
}

int main() {

    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;

    solveMaze(maze, n);
    
    return 0;
}