#include <iostream>
#include <vector>
#include <bits/stdc++.h>    
using namespace std;

vector<vector<int>> threeSum_bruteForce(vector<int> nums){
    set<vector<int>> st;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (nums[i] + nums[j] +nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSum_Optimized(vector<int> nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        if (i>0 && nums[i] == nums[i-1]) {
            continue;
        }

        int j = i+1;
        int k = n-1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && nums[j] == nums[j-1]) {
                    j++;
                }

                while (j<k && nums[k] == nums[k+1]) {
                    k--;
                }
            }

        }

    }

    return ans;
}

void printMat(vector<vector<int>> mat) {
    for(int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum_Optimized(arr);
    printMat(ans);

    return 0;
}