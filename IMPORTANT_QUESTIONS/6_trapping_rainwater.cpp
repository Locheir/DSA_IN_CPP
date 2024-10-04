#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int trapping_rainwater(int arr[], int n) {
    int leftMax[n];
    leftMax[0] = arr[0];

    for (int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    }

    printArr(leftMax, n);

    int rightMax[n];
    rightMax[n-1] = arr[n-1];

    for (int i=n-2; i>=0; i--) {
        rightMax[i] = max(rightMax[i+1], arr[i+1]);
    }

    printArr(rightMax, n);

    int waterCount = 0;

    for (int i=1; i<n-1; i++) {
        if(leftMax[i] > arr[i] && rightMax[i] > arr[i]) {
            waterCount += min(leftMax[i], rightMax[i]) - arr[i];
        }
    }

    return waterCount;
}

int trap_water(int *heights, int n) {
    int leftMax[20000];
    int rightMax[20000];

    leftMax[0] = heights[0];
    rightMax[0] = heights[n-1];

    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }

    printArr(leftMax, n);

    for(int i=n-2; i>=0; i--) {
        cout << i;
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
        cout << i << "=>" << rightMax[i+1] << "," << heights[i+1] << endl;
    }

    printArr(rightMax, n);

    int totalWaterTrapped = 0;

    for(int i=0; i<n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];
        if (currWater > 0) {
            totalWaterTrapped += currWater;
        }
    }

    return totalWaterTrapped;

}

int main() {

    int arr[] = {4, 2, 0, 6, 3, 2, 5};
    int arr2[] = {5,4,3,2,1};

    int n = sizeof(arr) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    cout << "Total Rain Water Trapped: " << trapping_rainwater(arr2, n2) << endl;
    cout << "Total Rain Water Trapped: " << trap_water(arr2, n2);
    return 0;
}