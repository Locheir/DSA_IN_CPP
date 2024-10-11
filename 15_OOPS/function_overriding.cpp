// Run Time Polymorphism

// Function Overriding :
// Parent & Child both contain the same function
// with different implementation. The parent class
// function is said to be overriden
#include <iostream>
using namespace std;

class Parent {
    public :
        void show() {
            cout << "parent class show.. \n";
        }
};

class Child : public Parent {
    public :
        void show() {
            cout << "child class show.. \n";
        }
};

int main() {
    Child child1;
    child1.show();

    return 0;
}