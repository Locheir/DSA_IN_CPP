#include <iostream>
#include <string>
using namespace std;

class Parent {
    public :
        Parent() {
            cout << "Constructor of parent \n";
        }
        ~Parent() {
            cout << "Destructor of parent \n";
        }
};

class Child : public Parent {
    public :
        Child() {
            cout << "Constructor of child \n";
        }
        ~Child() {
            cout << "Destructor of child \n";
        }
};

int main() {
    Child c1;
    return 0;
}