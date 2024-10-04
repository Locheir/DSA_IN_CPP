#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(char word[], int n) {
    int start = 0;
    int end = n-1;

    while(start <= end) {
        if (word[start] != word[end]){
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main() {
    char word[] = "naman";
    int n = strlen(word);

    if(palindrome(word, n)) {
        cout << word << " is a palindrome";
    } else {
        cout << word << " is not a palindrome";
    }

    return 0;
}