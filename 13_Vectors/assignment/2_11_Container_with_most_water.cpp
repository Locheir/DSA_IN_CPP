#include <iostream>
#include <vector>
using namespace std;

int maxArea_bruteForce(vector<int> height) {
    int max = 0;
    for (int i=0; i<height.size(); i++) {
        for (int j=i+1; j<height.size(); j++){
            int curr = (j-i)*min(height[j],height[i]);
            if (max < curr) {
                max = curr;
            }
        }
    }
    return max;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << maxArea_bruteForce(height);

    return 0;
}