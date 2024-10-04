#include <iostream>
using namespace std;

int main() {
    // Addition and subtraction of Pointers : 
    // 1. Addition : It is an invalid operation.
    // 2. Subraction : It can be used to find the 
    //    space between the two Pointers.

    int a = 5;
    int *ptr1 = &a;

    int *ptr2 = ptr1 + 3;

    cout << ptr2 << endl;
    cout << ptr1 << endl;
    cout << ptr2 - ptr1 << endl;

    // Array : 
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;
    int *ptrnext = ptr + 3;

    cout << *ptr << endl;
    cout << *ptrnext << endl;

    return 0;
}