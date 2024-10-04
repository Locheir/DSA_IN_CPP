#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *ptr = &a;
    float b = 10;
    float *ptrb = &b;
    float **ptrptrb = &ptrb;

    cout << &a << " = " << ptr << endl;
    cout << sizeof(ptr) << endl;
    cout << sizeof(ptrb) << endl;
    cout << ptrptrb << " = " << &ptrb;

    return 0;
}