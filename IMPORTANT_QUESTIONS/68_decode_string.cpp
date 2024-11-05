#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> number;
    stack<string> word;
    int n = 0;
    string sb;

    for(char c : s) {
        if (isdigit(c)) {
            n = n * 10 + (c - '0');
        } else if(c == '[') {
            number.push(n);
            n = 0;
            word.push(sb);
            sb = "";
        } else if (c == ']') {
            int k = number.top();
            number.pop();

            string temp = sb;
            sb = word.top();
            word.pop();

            while (k-- > 0) {
                sb += temp;
            }
        } else {
            sb += c;
        }
    }

    return sb;
};

int main() {
    string s = "3[a2[c]]";

    cout << decodeString(s);

    return 0;
}