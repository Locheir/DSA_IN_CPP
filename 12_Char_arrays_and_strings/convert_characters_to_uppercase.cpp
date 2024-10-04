#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n) {
    for (int i=0; i<n; i++) {
        if ((word[i] >= 'a') && (word[i] <= 'z')){
            int pos = word[i] - 'a';
            word[i] = 'A'+pos;
        }
    }
}

void toLower(char word[], int n) {
    for(int i=0; i<n; i++) {
        if ((word[i] >= 'A') && (word[i] <= 'Z')) {
            int pos = word[i] - 'A';
            word[i] = 'a'+pos;
        }
    }
}

int main() {
    char word[] = "abcDe";

    toUpper(word, strlen(word));

    cout << word << endl;

    toLower(word, strlen(word));

    cout << word << endl;

    return 0;
}