#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }
    int temp = s.top();
    s.pop();
    pushAtBottom(s, value);
    s.push(temp);

};

void printStack(stack<int> s) {
    int n = s.size();
    for(int i=0; i<n; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    printStack(s);

    pushAtBottom(s, 4);

    printStack(s);

    return 0;
}