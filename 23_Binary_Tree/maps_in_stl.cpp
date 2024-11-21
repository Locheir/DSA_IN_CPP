#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "rahul";
    m[110] = "neha";
    m[131] = "rahul";

    m[101] = "rajat";

    cout << m[101] << endl;

    // How to check if key is present or not : 
    cout << m.count(101) << endl; // if present returns 1 else returns 0

    for(auto it: m) {
        cout << it.first << " : " << it.second << endl;
    }
    return 0;
}