#include <iostream>
using namespace std;

int func(int arr[]) {
    // Arrays are call by reference.
    arr[0] = 1000;
}

void printArr(int arr[], int n) {

    for (int i=0; i<n; i++) {
        cout << "Value at index " << i << " : " << arr[i] << endl;
    }

}

int main() {
    int arr[] = {11, 22, 33, 44, 55};
    int n = sizeof(arr) / sizeof(int);

    cout << *arr << endl;       // arr[0]
    cout << *(arr+1) << endl;   // arr[1]
    cout << *(arr+2) << endl;   // arr[2]

    func(arr); // passing array name is basically passing a pointer
    cout << arr[0] << endl;

    printArr(arr, n);

    return 0;
}