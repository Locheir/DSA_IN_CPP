#include <iostream>
#include <string>
using namespace std;

int countLowerCase(string str) {
    int count = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count++;
        }
    }

    return count;
}

int main() {
    string str = "HEL";

    cout << countLowerCase(str);
    return 0;
}