#include <iostream>
#include <stack>
using namespace std;

class Queue {
    private :
        stack<int> s1;
        stack<int> s2;

    public :
    void push(int value) {
        // s1 -> s2;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // push value in s1;
        s1.push(value);

        // reverse and push in s1 again
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    } 

    void pop() {
        if (s1.empty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        s1.pop();
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    while (!q1.empty()) {
        cout << q1.front() << endl;
        q1.pop();
    }
    return 0;
}