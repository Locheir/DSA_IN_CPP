#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int arr[], int n) {

    for(int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;
        
        while (prev >= 0 && arr[prev] > curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr; 
    }

}

void countingSort(int arr[], int n) {

    
}

int main() {
    int arr[] = {3,6,2,1,9,7,4,5,3,1};
    int n = sizeof(arr) / sizeof(int);

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}