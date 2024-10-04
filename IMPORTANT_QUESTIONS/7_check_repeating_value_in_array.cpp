#include <iostream>
using namespace std;

bool check_repeating(int arr[], int n) {

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n-1; j++){
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int arr[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    if (check_repeating(arr, n)) {
        cout << "There are some values repeating";
    } else {
        cout << "There are no values that are repeating";
    }

    return 0;
}