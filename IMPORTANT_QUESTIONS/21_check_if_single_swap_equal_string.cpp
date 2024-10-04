#include <iostream>
#include <string>
using namespace std;

bool checkAlmostEqual(string s1, string s2) {
    if (s1 == s2) {
        return true;
    }

    for (int i=0; i<s2.length(); i++) {
        for (int j=i+1; j<s2.length(); j++) {
            char temp = s2[i];
            s2[i] = s2[j];
            s2[j] = temp;
            if (s2 == s1) {
                return true;
            } else {
                char temp = s2[i];
                s2[i] = s2[j];
                s2[j] = temp;
            }
        }
    }

    return false;
}

bool checkAlmostEqual_optimized(string s1, string s2) {
    if (s1 == s2) {
            return true;
        }

        int prev = -1; 
        int cnt = 0;

        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[i]) {
                if(prev != -1) {
                    swap(s1[i], s1[prev]);
                }
                prev=i;
                cnt++;
            }
        }

        if(s1==s2 && cnt==2) {
            return true;
        }
        return false;
}

int main() {
    string st1 = "hello";
    string st2 = "ehlol";

    cout << checkAlmostEqual(st1, st2);

    return 0;
}