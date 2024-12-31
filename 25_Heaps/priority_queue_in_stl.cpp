#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    // MAX HEAP

    // priority_queue<int> pq;

    // pq.push(13);
    // pq.push(3);
    // pq.push(7);
    // pq.push(4);
    // pq.push(1);

    // while(!pq.empty()) {
    //     cout << "top : " << pq.top() << endl;
    //     pq.pop();
    // }

    // MIN HEAP

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(13);
    pq.push(3);
    pq.push(7);
    pq.push(4);
    pq.push(1);

    while(!pq.empty()) {
        cout << "top : " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}