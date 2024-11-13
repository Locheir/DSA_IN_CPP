#include <iostream>
#include <string>
using namespace std;

string getSmallerString(int n, int k) {
    string ans(n,'a');
    k -= n;

    for(int i=n-1; i>=0; i--) {
        ans[n-1] += min(25, k);
        k -= min(25, k);
        n--;
    }

    return ans;
}

int main() {
    int n = 5;
    int k = 74;

    cout << getSmallerString(n, k);

    return 0;
}