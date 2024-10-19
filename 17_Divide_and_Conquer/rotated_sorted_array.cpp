#include <iostream>
using namespace std;

int advanceBinarySearch(int arr[], int si, int ei, int target) {
    if(si>ei) {
        return -1;
    }

    int mid = si+ (ei-si)/2;
    
    if(arr[mid] == target) {
        return mid;
    }

    if (arr[si] <= arr[mid]) {
        if (arr[si] <= target && target < arr[mid]) {
            advanceBinarySearch(arr, si, mid-1, target);
        } else {
            advanceBinarySearch(arr, mid+1, ei, target);
        }
    } else {
        if (arr[mid] < target && target <= arr[ei]) {
            advanceBinarySearch(arr, mid+1, ei, target);
        } else {
            advanceBinarySearch(arr, si, mid-1, target);
        }
    }
}

int main() {
    int arr[8] = {4, 5, 6, 7, 0, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << advanceBinarySearch(arr, 0, n-1, 5);

    return 0;
}