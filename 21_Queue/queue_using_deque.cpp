#include <iostream>
#include <deque>
using namespace std;

class Queue {
    private :
        deque<int> Q;

    public : 
        Queue() {

        }

        void push(int value) {
            Q.push_back(value);
        }

        void pop() {
            Q.pop_front();
        }

        int front() {
            return Q.front();
        }

        bool empty() {
            return Q.empty();
        }

        int size() {
            return Q.size();
        }
};

void printQueue(Queue q) {
    int n = q.size();

    for(int i=0; i<n; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {

    Queue q;

    for(int i=1; i<=5; i++) {
        q.push(i);
    }

    printQueue(q);
    
    return 0;
}