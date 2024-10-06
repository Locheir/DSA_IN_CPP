#include <bits/stdc++.h>
using namespace std;

void explainVector() {
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }

    vector<pair<int, int>> v2;

    v2.push_back({1, 2});
    v2.emplace_back(1, 2);

}

int main() {

    explainVector();
    return 0;
}