#include <iostream>
using namespace std;

int main() {
    int num;
    int new_num = 0;
    cout << "Enter a Number : ";
    cin >> num;
    
    int copy = num;

    while (copy > 0){
        int temp = copy % 10;
        new_num += temp*temp*temp;
        copy = copy / 10;
    }

    if (num == new_num) {
        cout << num << " is an armstrong number";
    } else {
        cout << num << " is not an armstrong number";
    }

    return 0;
} 
