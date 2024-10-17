// Print all Binary Strings of size N without any consecutive 1s

// 2 00 01 10
// 3 000 001 010 100 101 

#include <iostream>
#include <string>
using namespace std;

void binString(int n, int lastPlace, string ans) {
    if (n==0) {
        cout << ans << endl;
        return;
    }
    if(lastPlace != 1) {
    binString(n-1, 0, ans+'0');
    binString(n-1,1,ans+'1');
    } else {
        binString(n-1,0,ans+'0');
    }
}

int main() {
    string ans="";
    binString(3, 0, ans);
    return 0;
}