#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int currGas = 0;
    int totalGas = 0;
    int startIdx = 0;

    for(int i=0; i<gas.size(); i++) {
        int netGas = gas[i] - cost[i];
        currGas += netGas;
        totalGas += netGas;

        if (currGas < 0) {
            startIdx = i+1;

            currGas = 0;
        }
    }

    return totalGas >= 0 ? startIdx : -1;
}

int main() {
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};

    cout << canCompleteCircuit(gas, cost);

    return 0;
}