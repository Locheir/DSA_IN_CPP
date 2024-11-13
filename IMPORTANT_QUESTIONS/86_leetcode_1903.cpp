#include <iostream>
#include <string>
using namespace std;

string longestOddString(string s) {
    for(int i=s.size()-1; i>=0 ; i--) {
        int n = s[i] - '0';
        if (n%2 == 1) {
            return s.substr(0,i+1);
        }
    }

    return "";
}

int main() {
    string s = "756";

    cout << longestOddString(s);

    return 0;
}