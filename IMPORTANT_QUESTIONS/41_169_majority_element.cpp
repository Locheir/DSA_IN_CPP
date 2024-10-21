#include <iostream>
using namespace std;

// Moore's Voting Algorithm

int majorityElement(int arr[], int size) {
    int candidate = arr[0];
    int points = 1;

    for(int i=1; i<size; i++) {
        if (arr[i] != candidate && points == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate) {
            points++;
        } else {
            points--;
        }
    }

    return candidate;
}

int main() {

    int arr[] = {3,5,5,3,3,5,3,3,5,3};
    int size = 10;

    cout << majorityElement(arr, size);

    return 0;
}