#include <iostream>
using namespace std;

int main() {
    // Comparision of pointers :
    int arr[20] = {1, 2, 3, 4, 5, 6, 7};
    int *ptr = arr;
    
    cout << (ptr == arr) << "\n";

    return 0;
}