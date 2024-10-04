#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {

    for(int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

int main() {
    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting : ";
    printArr(arr, n);
    bubbleSort(arr, n);
    cout << "Array After Sorting : ";
    printArr(arr, n);


    return 0;
}