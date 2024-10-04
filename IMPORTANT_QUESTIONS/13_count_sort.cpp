#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n) {
    int freq_arr[100000] = {0};
    int minVal = INT8_MAX, maxVal = INT8_MIN;


    for(int i=0; i<n; i++) {
        freq_arr[arr[i]] += 1;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i=minVal, j=0; i<=maxVal; i++) {
        while(freq_arr[i] > 0) {
            arr[j] = i;
            freq_arr[i]--;
            j++;
        }
    }
}

int main() {
    int arr[] = {1,4,1,3,2,4,3,7};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    printArr(arr, n);
    
    countingSort(arr, n);

    cout << "Array After Sorting : ";
    printArr(arr, n);

    return 0;
}