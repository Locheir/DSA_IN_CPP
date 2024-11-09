#include <iostream>
#include <deque>
using namespace std;

class Stack {
    deque<int> DQ;

    public :
        
        void push(int x) {
            DQ.push_front(x);
        }

        void pop() {
            DQ.pop_front();
        }

        int top() {
            return DQ.front();
        }

        bool empty() {
            return DQ.empty();
        }

        int size() {
            return DQ.size();
        }
};

int main() {
    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    int n = s1.size();
    for(int i=0; i<n; i++) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    return 0;
}