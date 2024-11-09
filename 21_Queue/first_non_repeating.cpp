#include <iostream>
#include <queue>
using namespace std;

void first_non_repeating(string word) {
    int freq[26] = {0};
    queue<char> letters;

    for(int i=0; i<word.size(); i++) {
        char ch = word[i];
        letters.push(ch);
        freq[ch-'a']++;

        while(!letters.empty() && freq[letters.front()-'a'] > 1) {
            letters.pop();
        }

        if (letters.empty()) {
            cout << "-1" << endl;
        } else {
            cout << letters.front() << endl;
        }
    }
}

int main() {
    string st = "aabccxb";
    first_non_repeating(st);
    return 0;
}