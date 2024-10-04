#include <iostream>
using namespace std;

void printArr(int *ptr, int n) {
    for(int i=0; i<n; i++) {
        cout << *ptr + i << endl;
        ptr = ptr + 1;

        // Another way of printing : 
        // cout << *(ptr + i) << endl;
    }
}

int main() {
    // Addition & Subtraction of Constants with pointers.
    int a = 5;
    int *ptr = &a;

    cout << ptr << "\n";
    cout << (ptr + 3) << "\n\n";

    // Printing array :
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    printArr(arr, n);

    return 0;
}