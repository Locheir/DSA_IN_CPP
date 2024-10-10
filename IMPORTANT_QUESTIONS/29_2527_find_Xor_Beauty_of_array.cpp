#include <iostream>
#include <vector>
using namespace std;

int xorBeauty(vector<int> nums) {
    int res = nums[0];
    for (int i=1; i<nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}

int main() {

    vector<int> arr= {15,45,20,2,34,35,5,44,32,30};
    
    cout << xorBeauty(arr);

    return 0;
}