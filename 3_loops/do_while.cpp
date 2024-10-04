#include <iostream>
using namespace std;

int main() {

    int num;

    cout << "Enter your number : ";
    cin >> num;

    do {
        cout << num << endl;
        num--;
    }while(num>0);

    return 0;
}