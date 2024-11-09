#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> DQ) {
    int n = DQ.size();

    for(int i=0; i<n; i++) {
        cout << DQ.front() << " ";
        DQ.pop_front();
    }
    cout << endl;
}

int main() {
    deque<int> deq;

    deq.push_front(2);
    deq.push_front(1);

    deq.push_back(3);
    deq.push_back(4);

    printDeque(deq);

    deq.pop_front();

    printDeque(deq);

    deq.pop_back();
    
    printDeque(deq);

    return 0;
}