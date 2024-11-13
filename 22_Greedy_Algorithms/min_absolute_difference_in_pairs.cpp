#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int si, int ei, int mid) {
    vector<int> temp;
    int i=si;
    int j=mid+1;

    while (i<=mid && j<=ei) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=ei) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k=si, h=0; k<=ei; k++) {
        arr[k] = temp[h++];
    }
}

void mergeSort(vector<int> &arr, int si, int ei) {
    if(si>=ei) {
        return;
    }

    int mid = si + (ei-si) / 2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid);
};

int minAbsoluteDifference(vector<int> A, vector<int> B) {
    int result = 0;

    mergeSort(A, 0, A.size()-1);
    mergeSort(B, 0, B.size()-1);

    for(int i=0; i<A.size(); i++) {
        result += abs(A[i] - B[i]);
    }

    return result;
}

int main() {
    vector<int> A = {4, 1, 8, 7};
    vector<int> B = {2, 3, 6, 5};

    cout << minAbsoluteDifference(A, B);

    return 0;
}