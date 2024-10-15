#include <iostream>
#include <vector>
using namespace std;

int last_Occurence(vector<int> arr, int target, int i) {
    
    if(i==arr.size()) {
        return -1;
    }
    
    int idxFound = last_Occurence(arr, target, i+1);

    if (idxFound == -1 && arr[i] == target) {
            return i;
    }

    return idxFound;
    
}

int main() {
    vector<int> arr1 = {1,99,21,10,2,44,7,22,46,35};
    cout << last_Occurence(arr1, 0, 0);
    return 0;
}