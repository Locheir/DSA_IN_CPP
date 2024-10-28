#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubsets(string str, string ans) {
    if (str.size() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    printSubsets(str.substr(1,str.size()-1), ans+ch); // yes
    printSubsets(str.substr(1,str.size()-1), ans); // no
}

int main() {
    string str = "abc";
    string subset = "";

    printSubsets(str, subset);

    return 0;
}