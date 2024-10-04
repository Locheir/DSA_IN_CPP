#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

    }

    return -1;
}

int main() {
    int arr[] = { 1, 12, 24, 27, 31, 44, 52, 87, 88};
    int n = sizeof(arr) / sizeof(int);
    int key = 44;

    int res = binarySearch(arr, n, key);

    if (res==-1) {
        cout << "Element "<< key << " was not found in the array";
    } else {
        cout << "Element " << key << " was found at index " << res;
    }

    return 0;
}