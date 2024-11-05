#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool validParenthesis(string word) {
    stack<char> s;

    for(int i=0; i<word.size(); i++) {

        if(word[i] == '(' || word[i] == '{' || word[i] == '[') {

            s.push(word[i]);

        } else {

            if (s.empty()) {
                return false;
            }

            if (word[i] == ')' && s.top() == '(') {
                s.pop();
            } else if (word[i] == '}' && s.top() == '{') {
                s.pop();
            } else if (word[i] == ']' && s.top() == '[') {
                s.pop();
            } else {
                return false;
            }

        }

    }

    if (!s.empty()) {
        return false;
    } else {
        return true;
    }
}

int main() {

    cout << validParenthesis("([]{})") << endl;
    cout << validParenthesis("([)]") << endl;

    return 0;
}