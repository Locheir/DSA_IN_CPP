#include <iostream>
#include <vector>
using namespace std;

void merge(string arr[], int si, int ei, int mid) {
    vector<string> temp;
    int i=si;
    int j=mid+1;

    while(i<=mid && j<=ei) {
        if (arr[i] < arr[j]) {
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

    for(int k=si, x=0; k<=ei; k++) {
        arr[k] = temp[x++];
    }
}

void mergeSort(string arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei-si)/2;

    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si, ei, mid);
}

void printArr(string arr[], int size) {
    for (int i=0; i<size; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    string arr[4] = {"sun", "earth", "mars", "mercury"};
    int size = 4;

    mergeSort(arr, 0, size-1);

    printArr(arr, size);

    return 0;
}