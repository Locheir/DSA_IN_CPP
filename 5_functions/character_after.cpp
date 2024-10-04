#include <iostream>
using namespace std;

char next_char(char ch) {
    if (ch=='z'){
        return 'a';
    }

    return (char)(ch + 1);
}

int main() {
    char ch;

    cout << "Enter a character : ";
    cin >> ch;

    cout << "Next character : "<< next_char(ch);

    return 0; 
}