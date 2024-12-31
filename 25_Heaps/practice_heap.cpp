#include <iostream>
#include <vector>
using namespace std;

// Parent - Child Relationship (for 0 indexed): 
//   1. left child = 2*i + 1
//   2. right child = 2*i + 1

// From child find parent (for 0 indexed) : 
//  par_idx = (child_idx -1) / 2

class Heap {
    
    vector<int> arr;

    public : 
        void heapify(int parIdx) {
            if (parIdx >= arr.size()) {
                return;
            }

            int lft_chd = 2*parIdx + 1;
            int rgt_chd = 2*parIdx + 2;

            int maxIdx = parIdx;

            if(lft_chd < arr.size() && arr[lft_chd] > arr[maxIdx]) {
                maxIdx = lft_chd;
            }

            if (rgt_chd < arr.size() && arr[rgt_chd] > arr[maxIdx]) {
                maxIdx = rgt_chd;
            }

            swap(arr[parIdx], arr[maxIdx]);

            if (maxIdx != parIdx) {
                heapify(maxIdx);
            }
        }

        void push(int val) {
            arr.push_back(val);

            int child_idx = arr.size()-1;
            int parent_idx = (child_idx-1)/2;

            while(parent_idx>=0 && arr[child_idx] > arr[parent_idx]) {
                swap(arr[child_idx], arr[parent_idx]);
                child_idx = parent_idx;
                parent_idx = (child_idx-1)/2;
            }   
        }

        void pop() {
            swap(arr[0], arr[arr.size() - 1]);

            arr.pop_back();

            heapify(0);
        }

        int top() {
            return arr[0];
        }

        bool empty() {
            return arr.size() == 0;
        }

};

int main() {
    Heap hp;

    hp.push(10);
    hp.push(100);
    hp.push(90);

    while(!hp.empty()) {
        cout << hp.top() << " ";
        hp.pop();
    }
    return 0;
}