#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> Q) {
    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}

void interleaveQueue(queue<int> &Q1) {
    queue<int> Q2;
    int n = (Q1.size() / 2);

    for(int i=0; i<n; i++) {
        Q2.push(Q1.front());
        Q1.pop();
    }

    while (!Q2.empty()) {
        Q1.push(Q2.front());
        Q2.pop();
        Q1.push(Q1.front());
        Q1.pop();
    }
}

int main() {
    queue<int> Q1;

    for(int i=1; i<=10; i++) {
        Q1.push(i);
    }

    interleaveQueue(Q1);

    printQueue(Q1);

    return 0;
}