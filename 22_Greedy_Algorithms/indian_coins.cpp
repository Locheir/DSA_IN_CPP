#include <iostream>
#include <vector>
using namespace std;

int min_no_of_coins_Another_way(vector<int> coins, int V) {
    int ans = 0;
    int n = coins.size();

    for(int i=n-1; i>=0 && V>0; i--) {
        if (V >= coins[i]) {
            ans += V/coins[i];
            V = V%coins[i];
        }
    }
    
    return ans;
}

int min_no_of_coins(vector<int> coins, int num) {
    int count = 0;
    int currNum = 0;
    int n = coins.size()-1;

    while (currNum != num) {
        int remaining = num - currNum;

        for(int i=n; i>=0; i--) {
            if(coins[i] <= remaining) {
                count++;
                currNum += coins[i];
                cout << currNum << "  " << count << endl;
                break;
            }
        }

    }

    return count;
};

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};

    cout << min_no_of_coins_Another_way(coins, 590);

    return 0;
}