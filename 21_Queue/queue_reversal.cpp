#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQueue(queue<int> Q) {
    int n = Q.size();
    for(int i=0; i<n; i++) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
};

void reverseQueue(queue<int> &Q) {
    stack<int> S;

    while(!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }

    while(!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
};

int main() {
    queue<int> Q;

    for (int i=1; i<=5; i++) {
        Q.push(i);
    }

    printQueue(Q);

    reverseQueue(Q);

    printQueue(Q);

    return 0;
}