#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int time_required_to_buy_tickets(vector<int> tickets, int k) {
    queue<int> Q;
    int time = 0;

    for (int i=0; i<tickets.size(); i++) {
        Q.push(i);
    }

    while (!Q.empty()) {
        int n = Q.front();
        time++;
        tickets[n]--;
        Q.pop();

        if (tickets[n] == 0 && k == n) {
            return time;
        } 

        if (tickets[n] > 0) {
            Q.push(n);
        }
    }

    return -1;
};

int main() {
    vector<int> tickets = {5, 1, 1, 1};
    int k = 0;

    cout << time_required_to_buy_tickets(tickets, k);
    
    return 0;
}