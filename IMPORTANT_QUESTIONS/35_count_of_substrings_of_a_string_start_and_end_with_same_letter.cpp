#include <iostream>
using namespace std;

int count_substrings(string word, int start, int end, int n) {
    if (n==1) {
        return 1;
    }
    if (n<=0) {
        return 0;
    }

    int res = count_substrings(word, start+1, end, n-1) + count_substrings(word, start, end-1, n-1) - count_substrings(word, start+1, end-1, n-2);

    if (word[start] == word[end]) {
        res++;
    }

    return res;
}

int main() {
    string word = "abcd";
    int n = word.size();
    int start = 0;
    int end = n-1;
    
    cout << count_substrings(word, start, end, n);
    return 0;
}