#include <iostream>
#include <string>
using namespace std;

void printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool closeString(string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }
    int count1[26] = {0};
    int count2[26] = {0};
    for(int i=0; i<word1.length(); i++) {
        count1[word1[i]-'a']++;
        count2[word2[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        if (count1[i]>0 && !(count2[i]>0)) {
            return false;
        }
    }
    for(int i=0; i<26-1; i++) {
        for (int j=0; j<26-i-1; j++) {
            if(count1[j]>count1[j+1]) {
                int temp = count1[j];
                count1[j] = count1[j+1];
                count1[j+1] = temp;
            }
            if(count2[j]>count2[j+1]){
                int temp = count2[j];
                count2[j] = count2[j+1];
                count2[j+1] = temp;
            }
        }
    }
    for(int i=0; i<26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string w1 = "cabbba";
    string w2 = "abbccc";

    cout << closeString(w1, w2);

    return 0;
}