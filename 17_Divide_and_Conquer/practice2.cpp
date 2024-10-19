#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int size) {

    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int partition(int arr[], int si, int ei) {
    int pivot = arr[ei];
    int i = si-1;

    for (int j=si; j<ei; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    i++;
    swap(arr[i],arr[ei]);

    return i;
}

void quickSort(int arr[], int si, int ei) {
    if (si>=ei) {
        return;
    }

    int p_Idx = partition(arr, si, ei);

    quickSort(arr, si, p_Idx-1);
    quickSort(arr, p_Idx+1, ei);
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n-1);

    printArr(arr, n);

    return 0;
}