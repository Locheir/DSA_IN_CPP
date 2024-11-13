#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Job {
    public :
        int idx;
        int deadline;
        int profit;

        Job(int idx, int deadline, int profit) {
            this->idx = idx;
            this->deadline = deadline;
            this->profit = profit;
        }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();

    vector<Job> jobs;

    for(int i=0; i<n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) {
        return a.profit > b.profit;
    }); // lambda function

    cout << "Selecting Job " << jobs[0].idx << endl;;
    int total_profit = jobs[0].profit;
    int safeDeadLine = 2;

    for(int i=1; i<n; i++) {
        if(jobs[i].deadline >= safeDeadLine) {
            cout << "Selecting Job " << jobs[i].idx << endl;
            total_profit += jobs[i].profit;
            safeDeadLine++;
        }
    }

    return total_profit;
}

int main() {
    vector<pair<int, int>> jobs(4, make_pair(0,0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout << maxProfit(jobs);

    return 0; 
}