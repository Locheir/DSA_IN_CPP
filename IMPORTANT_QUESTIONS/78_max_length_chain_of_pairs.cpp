#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Same as Activity Selection : 

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int MaxLengthChainOfPairs(vector<pair<int, int>> arr) {
    sort(arr.begin(), arr.end(), compare);
    int count=1;
    int currEnd = arr[0].second;

    for(int i=1; i<arr.size(); i++) {
        if (arr[i].first >= currEnd) {
            count++;
            currEnd = arr[i].second;
        }
    }

    return count;
}

int main() {
    vector<pair<int, int>> arr = {
        {5, 24},
        {39, 60},
        {5, 28},
        {27, 40},
        {50, 90}
    };

    cout << MaxLengthChainOfPairs(arr);

    return 0;
}