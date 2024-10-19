#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int size) {
   
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void merge(int arr[], int si, int ei, int mid) {
    vector<int> temp;
    int i=si;
    int j=mid+1;

    while (i<=mid && j<=ei) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[j]);
            j++;
        } else {
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=ei) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k=si, x=0; k<=ei; k++) {
        arr[k] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei-si)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid);
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n-1);
    
    printArr(arr, n);

    return 0;
}