#include<iostream>
using namespace std;

// macros don't take space in the memory :
#define X 15

int main() {
    const int num = 25;
    int num2 = 35;

    // The below commented line will give an error 
    // It is not possible to redeclare a constant variable
    // num = 45;

    return 0;
}