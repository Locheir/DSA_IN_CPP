#include <iostream>
#include <vector>
using namespace std;

int maxActivitiesPossible(vector<int> start, vector<int> end) {
    int count = 1;
    int currEnd = end[0];

    cout << "Selecting Activity A0" << endl;

    for(int i=1; i<start.size(); i++) {
        if(start[i] >= currEnd) {
            count++;
            cout << "Selecting Activity A" << i << endl;
            currEnd = end[i];
        }
    }

    return count;
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxActivitiesPossible(start, end) << endl;

    return 0;
}