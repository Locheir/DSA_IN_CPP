#include <iostream>
using namespace std;

int* func() {
    int *ptr = new int;
    *ptr = 1200;
    cout << "Ptr points to " << *ptr << endl;

    return ptr;
}

int main() {
    // A memory leak occurs when programmers create a memory in heap
    // and forgot to delete it. Leads to reduced performance due to 
    // depletion of available memory.
    int *x = func();
    cout <<"x points to " << *x << endl;
    
    return 0;
}