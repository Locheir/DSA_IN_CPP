#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid+1;

    while(i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // vector -> org arr
    for (int idx=si, x=0 ; idx<=ei ; idx++ ) {
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si)/2; // another formula for avoiding overflow

    mergeSort(arr, si, mid); // left part
    mergeSort(arr, mid+1, ei); // right part

    merge(arr, si, mid, ei); // conquer
}

void printArr(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    mergeSort(arr, 0, n-1);

    printArr(arr, n);

    return 0;
}