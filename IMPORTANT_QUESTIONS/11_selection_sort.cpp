#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    
    for (int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

}

void printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 4, 1, 3 ,2};
    int n = sizeof(arr) / sizeof(n);

    cout << "Array Before Sorting : ";
    printArr(arr, n);

    selectionSort(arr, n);

    cout << "Array After Sorting : ";
    printArr(arr, n);

    return 0;
}