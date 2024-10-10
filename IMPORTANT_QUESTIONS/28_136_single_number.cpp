#include <iostream>
#include <vector>
using namespace std;

int find_single_number(vector<int> nums) {
    int res = 0;

    for (int i=0; i<nums.size(); i++) {
        res = res ^ nums[i];
    }

    return res;
}

int main() {
    vector<int> arr = {2,2,4,1,3,1,4};
    
    cout << find_single_number(arr);
    
    return 0;
}