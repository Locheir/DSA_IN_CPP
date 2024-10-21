#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;

void merge(int arr[], int si, int ei, int mid) {
    int i=si;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=ei) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            cnt += (mid-i+1);
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

    for (int k=si,x=0; k<=ei; k++) {
        arr[k] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei-si)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid);
}

int count_no_of_inversions(int arr[], int size) {
    mergeSort(arr, 0, size-1);
    return cnt;
}

int main() {
    // int arr[] = {2,4,1,3,5};
    int arr[] = {5,3,2,4,1};
    int size = 5;

    cout << count_no_of_inversions(arr, 5);

    return 0;
}