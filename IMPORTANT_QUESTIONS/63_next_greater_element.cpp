#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int> &arr, vector<int> &greater) {
    stack<int> s;
    int n = arr.size();
    s.push(arr[n-1]);
    greater[n-1] = -1;
    
    for(int i=n-2; i>=0; i--) {
        while (!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }
        
        if (s.empty()) {
            greater[i] = -1;
        } else {
            greater[i] = s.top();
        }

        s.push(arr[i]);
    }
};

void printArr(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
};

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> greater = {0, 0, 0, 0, 0};

    nextGreater(arr, greater);

    printArr(greater);

    return 0;
}