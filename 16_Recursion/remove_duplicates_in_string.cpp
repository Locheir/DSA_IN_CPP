#include <iostream>
#include <string>
using namespace std;

void remove_duplicates(string word, string ans, int i, int map[26]) {

    if(i == word.size()) {
        cout << "ans : " << ans << endl;
        return;
    }

    int mapIdx = (int) (word[i] - 'a');

    if(map[mapIdx]) {
        remove_duplicates(word, ans, i+1, map);
    } else {
        map[mapIdx] = true;
        remove_duplicates(word, ans+word[i], i+1, map);
    }
}

void remove_duplicates2(string word, string ans, int map[26]) {

    if(0 == word.size()) {
        cout << "ans : " << ans << endl;
        return;
    }
    int n = word.size();
    char ch = word[n-1];
    int mapIdx = (int) (word[n-1] - 'a');
    word = word.substr(0,n-1);

    if(map[mapIdx]) {
        remove_duplicates2(word, ans, map);
    } else {
        map[mapIdx] = true;
        remove_duplicates2(word, ch+ans, map);
    }
}

int main() {
    string word = "aaabbb";
    string ans = "";
    int map[26] = {false};
    remove_duplicates2(word, ans, map);
    return 0;
}