#include <iostream>
using namespace std;

class A {
    string secret = "secret data";
    friend class B;
    friend void revealSecret(A &obj);
};

class B {
    public :
        void showSecret(A &obj) {
            cout << obj.secret << endl;
        }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}

int main() {
    A a1;
    B b1;

    b1.showSecret(a1);
    revealSecret(a1);
    return 0;
}