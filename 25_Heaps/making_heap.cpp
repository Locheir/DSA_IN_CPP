#include <iostream>
#include <string>
#include <vector>
using namespace std;

// For Heaps : 
// parent_idx = i
// leftChild = 2*i + 1
// rightChild = 2*i + 2

// For Finding Parent from Child : 
// child_idx = x
// parent_idx = (x-1) / 2

class Heap{
    vector<int> vec;

    public :

        void push(int val) { // O(log n)
            // Push in vector
            vec.push_back(val);

            // fix Heap
            int x = vec.size()-1;
            int parI = (x-1)/2;

            while(parI >=0 && vec[x] > vec[parI]) {
                swap(vec[x], vec[parI]);
                x = parI;
                parI = (x-1)/2;
            }
        }

        void heapify(int i) {
            if (i >= vec.size()) {
                return;
            }

            int l = 2*i + 1;
            int r = 2*i + 2;

            int maxIdx = i;

            if (l < vec.size() && vec[l] > vec[maxIdx]) {
                maxIdx = l;
            } 

            if (r < vec.size() && vec[r] > vec[maxIdx]) {
                maxIdx = r;
            }

            swap(vec[i], vec[maxIdx]);

            if (maxIdx != i) { // swaping with child node.
                heapify(maxIdx);
            }
        }

        void pop() {
            // swap the first and last value.
            swap(vec[0], vec[vec.size()-1]);
            
            // pop the last element in vector.
            vec.pop_back();

            // call heapify : that fixes the heap.
            heapify(0);
        }

        int top() {
            return vec[0];
        }

        bool empty() {
            return vec.size() == 0;
        }

};

int main() {
    Heap h;
    h.push(9);
    h.push(4);
    h.push(8);
    h.push(1);
    h.push(2);
    h.push(5);

    while(!h.empty()) {
        cout << "Top Value : " << h.top() << endl;
        h.pop();
    }
}