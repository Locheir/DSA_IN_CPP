#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int stockSpan(vector<int> arr, vector<int> span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i=1; i<arr.size(); i++) {
        int current = arr[i];
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            span[i] = i+1;
        } else {
            span[i] = i-(s.top());
        }
        s.push(i);
    }

    int max = span[0];
    cout << span[0] << " ";
    for(int i=1; i<span.size(); i++) {
        cout << span[i] << " ";
        if (span[i] > max) {
            max = span[i];
        }
    }
    cout << endl;
    
    return max;
};

int main() {
    vector<int> arr = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};

    cout << stockSpan(arr, span);

    return 0;
}