#include <iostream>
using namespace std;

void printArr(char arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insetionSort(char arr[], int n) {
    for (int i=1; i<n; i++) {
        int curr = arr[i];
        int prev = i-1;
        
        while(prev >= 0 && curr > arr[prev]) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr;
    }
}

int main() {
    char arr[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int n = sizeof(arr) / sizeof(char);

    insetionSort(arr, n);
    printArr(arr, n);

    return 0;
}