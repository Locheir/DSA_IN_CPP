#include <iostream>
#include <limits.h>

using namespace std;

int max_sum_brute_force(int arr[], int n) {
    int max = INT_MIN;

    for (int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            cout << sum << endl;
            if (max < sum){
                max = sum;
            }
        }
    }

    return max;
}

int max_sum_slightly_optimized(int arr[], int n) {
    int max = INT_MIN;

    for (int i=0; i<n; i++){
        int curr_sum = 0;
        for (int j=i; j<n; j++){
            curr_sum += arr[j];
            if (max < curr_sum) {
                max = curr_sum;
            }
        }
    }

    return max;
}

int max_sum_kadanes_algo(int arr[], int n) {
    int max = INT_MIN;
    int currSum = 0;

    for(int i=0; i<n; i++){
        currSum += arr[i];
        if (max < currSum) {
            max = currSum;
        }
        if (currSum < 0) {
            currSum = 0;
        }
        cout << max;
    }

    return max;
}

int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    int max = arr[0];

    cout << "Maximum : " << max_sum_brute_force(arr, n) << endl;
    cout << "Maximum : " << max_sum_slightly_optimized(arr, n)<< endl;
    cout << "Maximum : " << max_sum_kadanes_algo(arr, n) << endl;

    return 0;
}