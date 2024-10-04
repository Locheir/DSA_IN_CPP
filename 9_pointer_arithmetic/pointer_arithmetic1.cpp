#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6};
    int *ptr = arr;

    cout << ptr << endl;
    ptr++;
    cout << ptr << "\n\n";

    char ch = 'a';
    char *chptr = &ch;

    cout << chptr << endl;
    chptr++;
    cout << chptr << endl;


    return 0;
}