#include <iostream>
#include <cstring>
using namespace std;

void reverseArr(char word[], int n) {
    int start = 0;
    int end = n-1;
    while(start <= end) {
        int temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char word[] = "mohit";

    reverseArr(word, strlen(word));

    cout << word;

    return 0;
}