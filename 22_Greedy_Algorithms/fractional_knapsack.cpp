#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

int fractionKnapsack(vector<int> &value , vector<int> &weight, int capacity) {
    vector<pair<int, int>> weight_perKg(weight.size(), make_pair(0,0));

    for(int i=0; i<weight.size(); i++) {
        weight_perKg[i] = make_pair(weight[i], value[i]/weight[i]);
    }

    sort(weight_perKg.begin(), weight_perKg.end(), compare);

    int totalWeight = 0;
    int MaxValue = 0;

    for(int i=0; i<weight.size(); i++) {
        int n = capacity - totalWeight;
        if (n >= weight_perKg[i].first) {
            totalWeight += weight_perKg[i].first;
            MaxValue += weight_perKg[i].second * weight_perKg[i].first;
            cout << totalWeight << "   " << n << "   " << weight_perKg[i].first*weight_perKg[i].second <<  endl;
        } else {
            totalWeight += n;
            MaxValue += weight_perKg[i].second * n;
            cout << totalWeight << "   " << n << "   " << weight_perKg[i].second*n <<  endl;
            break;
        }
    }

    return MaxValue;
}

int main() {
    vector<int> value = {60, 100, 120};
    vector<int> weight = {5, 20, 30};
    int capacity = 50;

    cout << fractionKnapsack(value, weight, capacity);    

    return 0;
}