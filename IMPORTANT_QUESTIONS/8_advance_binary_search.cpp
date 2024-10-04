#include <iostream>
using namespace std;

int advanceBinarySearch(int arr[], int n, int key) { 
    int start = 0;
    int end = n-1;

    while(start < end) {
        int mid = (start + end)/2;
        if (arr[mid] == key) {
            return mid;
        }

        if (arr[start] < arr[mid]) {
            if (arr[start] <= key && arr[mid] > key) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        } else {
            if (arr[mid] < key && arr[end] >= key) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }   
    }

    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    int key = 1;

    int result = advanceBinarySearch(arr, n, key);

    if (result == -1) {
        cout << "Element " << n << " is not present in the array";
    } else {
        cout << "Element " << n << " is found at index " << result;
    }
    return 0;
}