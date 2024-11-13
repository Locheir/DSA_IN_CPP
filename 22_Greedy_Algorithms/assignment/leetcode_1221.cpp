#include <iostream>
#include <string>
using namespace std;

int possibleBalancedString(string s) {
    int count = 0;
    int l_cnt = 0;
    int r_cnt = 0;

    for(int i=0; i<s.size(); i++) {
        if (s[i] == 'L') {
            l_cnt++;
        } else {
            r_cnt++;
        }

        if (l_cnt == r_cnt) {
            count++;
            l_cnt = 0;
            r_cnt = 0;
        }
    }

    return count;
}

int main() {
    string s = "RLRRRLLRLL";

    cout << possibleBalancedString(s);

    return 0;
}