#include <iostream>
using namespace std;

int main() {

    int num;
    int a = 0;
    int b = 1;

    cout << "Enter a Number : ";
    cin >> num;

    if (num==1) {
        cout << 0 << endl;
    } else if (num==2) {
        cout << 0 << endl;
        cout << 1 << endl;
    } else {
        cout << a << endl;
        cout << b << endl;

        for (int i=3; i<=num; i++){
            int c = a+b;
            cout << c << endl;
            a = b;
            b = c;
        }
    }

    return 0;
}