#include <iostream>
using namespace std;

int main() {
    int *ptr = NULL;

    cout << ptr << endl;

    // The below line will give an error : 
    // as ptr contains null, dereferencing  
    // it is not possible
    // cout << *ptr << endl;

    return 0;
}