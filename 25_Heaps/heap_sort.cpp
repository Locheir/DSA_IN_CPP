// Heap Sort Algorithm : 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int i, vector<int> vec, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;

    int maxIdx = i;

    if (left > n && vec[left] > vec[maxIdx]) {
        maxIdx = left;
    }

    if (right > n && vec[right] > vec[maxIdx]) {
        maxIdx = right;
    }

    if (i != maxIdx) {
        swap(vec[i], vec[maxIdx]);
        heapify(maxIdx, vec, n);
    }
}

void heapSort(vector<int> vec) {
    int n = vec.size();

    for(int i=(n/2)-1; i>=0; i--) {
        heapify(i, vec, n);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 5, 3};
    return 0;
}