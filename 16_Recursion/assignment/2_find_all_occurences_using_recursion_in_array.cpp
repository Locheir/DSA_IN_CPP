#include <iostream>
#include <vector>
using namespace std;

void find_occurences(vector<int> arr, int target, int i) {
    if (i == arr.size()) {
        return;
    }

    if (arr[i] == target) {
        cout << i << " ";
        find_occurences(arr, target, i+1);
    } else {
        find_occurences(arr, target, i+1);
    }
}

int main() {
    vector<int> arr = {1,2,3,2,4,5,6,2,7,3,3,1,2,9};
    find_occurences(arr, 2, 0);
    return 0;
}