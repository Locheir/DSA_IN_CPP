#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {

    for (int i=0; i<n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {12,33,99,22,13,10,25,74,45};
    int n = sizeof(arr) / sizeof(int);
    int key = 100;

    int res = linearSearch(arr, n, key);

    if (res==-1) {
        cout << "Element " << key << " was not found in the array" << endl;
    } else {
        cout << "Element " << key << " was found at index " << res; 
    }
}