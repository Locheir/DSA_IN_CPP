#include <iostream>
using namespace std;

int main() {
    // making an array of 50 size 
    // range ( 0 - 49 )
    int marks[50];

    cout << marks[0] << endl;
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;
    // The above lines are giving garbage value
    // as we have not set any value for them.

    int marks2[10] = {1,2,3};
    // when we initiate some values in an array 
    // the other values that are not initiated 
    // are automatically saved as 0.

    cout << marks2[0] << endl;
    cout << marks2[1] << endl;
    cout << marks2[2] << endl;
    cout << marks2[3] << endl;

    // printing size of array : 
    int marks3[5] = {1, 2, 3, 4, 5};

    cout << sizeof(marks3)/sizeof(int) << endl;

    return 0;
}