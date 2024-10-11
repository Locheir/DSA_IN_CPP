#include <iostream>
using namespace std;

// Variables declared as static in function are created &
// inititalized once for the lifetime of the program.

// static variable in a class are created and initialized once.

void count() {
    static int cnt = 0;
    cnt++;
    cout << cnt << endl;
}

class Example {
    public :
        static int x;
};

int Example::x = 0;

int main() {
    count();
    count();
    count();


    Example e1;
    Example e2;
    Example e3;

    cout << e1.x++ << endl; //0
    cout << e2.x++ << endl; //1
    cout << e3.x++ << endl; //2

    return 0;
}