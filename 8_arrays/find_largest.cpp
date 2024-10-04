#include <iostream>
using namespace std;

int main() {
    int arr[] = {17,21,38,4,25,36,7};
    int n = sizeof(arr) / sizeof(int);
    int max = arr[0];

    for(int i=1; i<n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    cout << "Maximum in Array : " << max;

    return 0;
}

