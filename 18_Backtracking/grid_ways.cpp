#include <iostream>
#include <vector>
using namespace std;

int gridWays(int row, int col, int n, int m, string ans) {
    if(row==n-1 && col==m-1) {
        cout << ans << "\n";
        return 1;
    }

    if (row>=n) {
        return 0;
    }

    if (col>=m) {
        return 0;
    }

    // right 
    int way1 = gridWays(row, col+1, n, m, ans+"R");
    
    // down
    int way2 = gridWays(row+1, col, n, m, ans+"D");

    return way1+way2;
}

int fact(int num) {
    int facto = 1;
    for(int i=1; i<=num; i++) {
        facto = facto*i;
    }
    return facto;
}

int gridWays_linear_solution(int n, int m) {
    return (fact(n-1+m-1))/(fact(n-1)*fact(m-1));
}

int main() {
    int n = 3;
    int col = 3;

    cout << gridWays(0, 0, 3, 3, "") << endl;
    cout << gridWays_linear_solution(3,3);
    return 0;
}