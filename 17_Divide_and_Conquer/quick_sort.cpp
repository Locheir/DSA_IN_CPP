#include <iostream>
#include <vector>
using namespace std;

// Quick Sort : Pivot & Partition Approach

void printArr(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int si, int ei) {
    int i = si-1;
    int pivot = arr[ei];

    for (int j=si; j<ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    
    i++;
    swap(arr[i],arr[ei]);

    return i;
}

void quickSort(int arr[], int si, int ei) {

    if (si >= ei) {
        return;
    }

    int pivotIdx = partition(arr, si, ei);

    quickSort(arr, si, pivotIdx-1); // left half 
    quickSort(arr, pivotIdx+1, ei); // right half
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n-1);

    printArr(arr, n);

    return 0;
}