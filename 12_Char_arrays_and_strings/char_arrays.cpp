#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[5] = {'c', 'o', 'd', 'e', '\0'};
    cout << str << endl;

    char work[] = "coding";
    cout << work;
    cout << strlen(work) << endl;

    return 0;
}