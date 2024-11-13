#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printPairs(vector<pair<int, int>> VP) {
    int n = VP.size();

    for(int i=0; i<n; i++) {
        cout <<"("<< VP[i].first << ", " << VP[i].second << ")  ";
    }
    cout << endl;
}

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    vector<int> start = {0, 1, 2};
    vector<int> end = {9, 2, 4};

    vector<pair<int, int>> activity(start.size(), make_pair(0, 0));

    for(int i=0; i<activity.size(); i++) {
        activity[i] = make_pair(start[i], end[i]);
    }

    printPairs(activity);

    sort(activity.begin(), activity.end(), compare);

    printPairs(activity);

    return 0;
}