#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
};

void nextSmallerRight(vector<int> &heights, vector<int> &rightSmall) {
    stack<int> s;
    int n = heights.size();
    rightSmall[n-1] = n;
    s.push(n-1);

    for(int i=n-2; i>=0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if (s.empty()) {
            rightSmall[i] = n;
        } else {
            rightSmall[i] = s.top();
        }

        s.push(i);
    }
};

void nextSmallerLeft(vector<int> &heights, vector<int> &leftSmall) {
    stack<int> s;
    int n = heights.size();
    s.push(0);
    leftSmall[0] = -1;

    for(int i=0; i<n; i++){
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if (s.empty()) {
            leftSmall[i] = -1;
        } else {
            leftSmall[i] = s.top();
        }

        s.push(i);
    }
    
}

int maxAreaInHistogram(vector<int> heights) {
    int n = heights.size();
    vector<int> leftSmall(n);
    vector<int> rightSmall(n);
    int maxArea = 0;

    nextSmallerLeft(heights, leftSmall);
    nextSmallerRight(heights, rightSmall);

    for(int i=0; i<n; i++) {
        int currArea = heights[i] * (rightSmall[i] - leftSmall[i] - 1);

        if(maxArea < currArea) {
            maxArea = currArea;
        }
    }

    return maxArea;
};

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    vector<int> arr2 = {2,4};

    cout << maxAreaInHistogram(arr2) << endl;

    return 0;
}