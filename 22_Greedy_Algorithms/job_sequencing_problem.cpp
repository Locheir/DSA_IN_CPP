#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

// Every Activity will take one day to complete.
int maximizeProfit(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int safeDeadLine = 1;
    int profit = 0;

    for(int i=0; i<jobs.size(); i++) {
        if (jobs[i].first >= safeDeadLine) {
            profit += jobs[i].second;
            safeDeadLine++;
        }
    }

    return profit;
}

int main() {
    vector<pair<int, int>> jobs(4, make_pair(0,0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout << maximizeProfit(jobs);

    return 0;
}