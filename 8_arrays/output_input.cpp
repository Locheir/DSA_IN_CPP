#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter Length of Array : ";
    cin >> n;

    int arr[n];

    for (int i=0; i<n; i++) {
        cout << "Enter value on index " << i << " : ";
        cin >> arr[i];
    }

    for (int i=0; i<n ; i++){
        cout << "Value at index " << i << " : " << arr[i] << endl;
    }

    return 0;
}