#include <iostream>
#include <string>
using namespace std;

void printArr(int arr[], int size) {
    for (int k=0; k<size; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

bool isAnagram(string str1, string str2) {
    if (str1.length() != str2.length()){
        return false;
    }
    int count[26] = {0};

    for (int i=0; i<str1.length(); i++) {
        int pos = str1[i]-'a';
        count[pos]++;

    }

    printArr(count, 26);

    for (int j=0; j<str2.length(); j++) {
        int pos = str2[j] - 'a';
        if(count[pos] == 0){
            return false;
        }
        count[pos]--;
    }

    return true;
}

int main() {
    string str = "anagram";
    string str2 = "arganam";

    cout << isAnagram(str, str2);

    return 0;
}