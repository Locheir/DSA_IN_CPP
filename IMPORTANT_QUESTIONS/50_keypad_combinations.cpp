#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bfs(int pos, int len, string ans, string digits, string arr[]) {
    if (pos==len) {
        cout << ans << endl;
    } else {
        int ch = digits[pos] - '0';
        string letters = arr[ch];
        for (int i=0; i<letters.size(); i++) {
            bfs(pos+1, len, ans+letters[i], digits, arr);
        }
    }
}

void keypadCombination(string digits, string arr[]) {
    int len = digits.size();
    if (len==0) {
        cout << "";
        return;
    }

    string ans = "";
    bfs(0, len, ans, digits, arr);
}

int main() {
    string arr[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    string digits = "23";

    keypadCombination(digits, arr);
    return 0;
}