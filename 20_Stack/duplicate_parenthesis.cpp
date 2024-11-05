#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool duplicateParenthesis(string str) {
    stack<char> s;

    for (int i=0; i<str.size(); i++) {
        if(str[i] == ')') {
            if (s.top() == '(') {
                return true;
            }else {
                while(s.top() != '(') {
                    s.pop();
                }
                s.pop();
            }
        } else {
            s.push(str[i]);
        }
    }

    return false;
}

int main() {
    string str = "(((x)))";
    string str2 = "((x+y)+z)";
    cout << duplicateParenthesis(str) << endl;
    cout << duplicateParenthesis(str2) << endl;
    return 0;
}