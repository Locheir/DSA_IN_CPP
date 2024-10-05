#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr, int size){
    for (int i=1; i<=size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> set_mismatch(vector<int> nums) {
    vector<int> frequency(nums.size()+1);
    vector<int> res;
    for (int i=0; i<nums.size(); i++) {
        if(frequency[nums[i]] == 1) {
            res.push_back(nums[i]);
        }
        if(frequency[nums[i]] == 0) {
            frequency[nums[i]]++;
        }
    }
    
    for (int i=1; i<=nums.size(); i++) {
        if(frequency[i] == 0){
            res.push_back(i);
            break;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 2, 4};

    vector<int> ans = set_mismatch(arr);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}