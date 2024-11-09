#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstKelements(queue<int> &Q, int k) {
    int n = Q.size();

    stack<int> S;

    for(int i=0; i<k; i++) {
        S.push(Q.front());
        Q.pop();
    }

    for(int i=0; i<k; i++) {
        Q.push(S.top());
        S.pop();
    }

    for(int i=0; i<n-k; i++) {
        int n = Q.front();
        Q.pop();
        Q.push(n);
    }

};

void printQueue(queue<int> Q) {
    int n = Q.size();

    for(int i=0; i<n; i++) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> Q;

    for(int i=1; i<=5; i++) {
        Q.push(i);
    }
    int k = 3;

    printQueue(Q);

    reverseFirstKelements(Q, k);

    printQueue(Q);

    return 0;
}