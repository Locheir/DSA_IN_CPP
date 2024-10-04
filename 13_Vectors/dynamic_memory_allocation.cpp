#include <iostream>
using namespace std;

int main() {
    // Creating a static array : 
    // int arr1[100] = {1, 2, 3, 4, 5};
    
    // Creating array dynamically : 
    int size;
    cout << "Enter Size : ";
    cin >> size;

    int *arr = new int[size];
    // arr[0] => *(arr+0)
    // arr[1] => *(arr+1)
    // arr[2] => *(arr+2)

    int x=1;
    for(int i=0; i<size; i++) {
        arr[i] = x;
        cout << arr[i] << " ";
        x++;
    }
    cout << endl;

    // always delete the memory that is allocated dynamically.
    // because the memory is not deleted automatically.
    delete [] arr;

    return 0;
}