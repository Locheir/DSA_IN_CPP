#include <iostream>
using namespace std;

bool check_array_sorted(int arr[], int size, int i) {
    if (i == size-1) {
        return true;
    }
    if (arr[i] > arr[i+1]) {
        return false;
    }
    return check_array_sorted(int arr[], int size, i+1);
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    cout << check_array_sorted(arr1, 5, 0);
    return 0;
}