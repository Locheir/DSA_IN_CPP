#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // char word[10];
    // cout << "Enter a single word : " ;
    // cin >> word; // This ignores white space

    // cout << "Your word was : " << word << endl;
    // cout << "Length : " << strlen(word) << endl;

    char sentence[40];
    cout << "Enter a Sentence : ";
    cin.getline(sentence, 40);

    cout <<"Your sentence is : " << sentence << endl;
    cout <<"Length : " << strlen(sentence) << endl;

    return 0;
}