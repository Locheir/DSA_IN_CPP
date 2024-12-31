#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<pair<string, int>> pq;

    pq.push(make_pair("mohit",90));
    pq.push(make_pair("yash",89));
    pq.push(make_pair("rahul",88));

    while(!pq.empty()) {
        cout << "Top : " << pq.top().first << " , " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}