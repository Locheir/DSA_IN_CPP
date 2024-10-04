#include <iostream>
using namespace std;

void printArr(int arr[], int n){

    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void reverseArr(int arr[], int n) {
    int i=0;
    int j=n-1;

    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr) / sizeof(int);

    printArr(arr, n);

    reverseArr(arr, n);

    printArr(arr, n);

    return 0;
}