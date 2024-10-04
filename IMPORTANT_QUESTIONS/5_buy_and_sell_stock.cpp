#include <iostream>
#include <limits.h>
using namespace std;

int max_profit(int *prices, int n) {
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;

    for (int i=1; i<n; i++) {
        if (bestBuy[i-1] > prices[i-1]) {
            bestBuy[i] = prices[i-1];
        } else {
            bestBuy[i] = bestBuy[i-1];
        }
    }

    int maxProfit = 0;
    for(int i=0; i<n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        if (maxProfit < currProfit) {
            maxProfit = currProfit;
        }
    }

    return maxProfit;

}

int main() {

    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    cout << "Maximum Profit Possible : " << max_profit(arr, n);

    return 0;
}