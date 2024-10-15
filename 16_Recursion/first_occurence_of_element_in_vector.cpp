#include <iostream>
#include <vector>
using namespace std;

int first_occurence(vector<int> arr, int target, int i) {
    if (i==arr.size()) {
        return -1;
    }
    if (arr[i] == target) {
        return i;
    }
    return first_occurence(arr, target, i+1);
}

int main() {
    vector<int> arr1 = {1,99,10,2,44,7,21,46,35};
    cout << first_occurence(arr1, 99, 0);
    return 0;
}