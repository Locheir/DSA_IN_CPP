#include <iostream>
using namespace std;

void printArr(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int i) {
    if(i==n) {
        printArr(arr, n);
        return;
    }
    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;
}

int main() {
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(int);

    changeArr(arr, n, 0);

    printArr(arr, n);

    return 0;
}