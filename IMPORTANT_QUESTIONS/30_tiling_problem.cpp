#include <iostream>
using namespace std;

// Count total ways to tile a floor (2xn) with tiles (2x1)
// in this file, we are not learning the most optimal approach
// we will learn the best approach in Dynamic Programming
// for now we will learn how to find the answer using recursion.
// Time Complexity = Exponential (very bad time complexity)

int tiling_problem(int n) {
    if (n==0 || n==1) {
        return 1;
    }

    return tiling_problem(n-1) + tiling_problem(n-2);
}

int main() {
    cout << tiling_problem(41);
    return 0;
}