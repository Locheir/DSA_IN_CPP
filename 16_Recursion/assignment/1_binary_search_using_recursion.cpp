#include <iostream>
using namespace std;

// int binary_search_recursion(int arr[], int start, int end, int target) {
//     if (start > end) {
//         return -1;
//     }

//     int mid=(start + end)/2;

//     if (arr[mid] == target) {
//         return mid;
//     }

//     if (arr[mid] < target) {
//         return binary_search_recursion(arr, mid+1, end, target);
//     } else {
//         return binary_search_recursion(arr, start, mid-1, target);
//     }
// }

int binary_search_recursion(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1;  // Target not found
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target) {
        return mid;  // Target found
    }

    if (arr[mid] > target) {
        return binary_search_recursion(arr, start, mid-1, target);  // Search left half
    } else {
        return binary_search_recursion(arr, mid+1, end, target);  // Search right half
    }
}


int main() {

    int arr[] = {1,11,18,22,32,40,55,58,60,61,77,82};
    int target = 61;
    int start = 0;
    int end = sizeof(arr) / sizeof(int);

    int ans = binary_search_recursion(arr, start, end, target);
    
    cout << ans;

    return 0;
}