#include <iostream>
#include <vector>
using namespace std;

// Finding target in SORTED ARRAY :
vector<int> pairSum_bruteForce(int arr[],int size, int target) {
    vector<int> result;
    for(int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if ((arr[i] + arr[j])==target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

}

vector<int> pairSum_Optimized(int arr[], int n, int target) {\
    vector<int> vec;
    int start = 0;
    int end = n-1;
    while(start < end) {
        int curr = arr[start]+arr[end];
        if ((curr)== target) {
            vec.push_back(start);
            vec.push_back(end);
            return vec;
        }
        if (curr < target) {
            start++;
        } else {
            end--;
        }
    }
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr)/sizeof(int);
    int target = 9;

    vector<int> vec = pairSum_Optimized(arr, n, target);
    for(int i=0; i<2; i++){
        cout << vec[i] << " ";
    }

    return 0;
}