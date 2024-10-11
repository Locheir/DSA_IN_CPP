#include <iostream>
using namespace std;

// Virtual Function :
// It is a member function that you expect
// to redefine in derived classes.

class Parent {
    public :
        virtual void hello() {
            cout << "parent's hello..\n";
        }
};

class Child : public Parent {
    public :
        void hello() {
            cout << "child's hello..\n"
        }
}

int main() {
    Child child1;
    Parent *ptr;

    ptr = &child1; //Run Time Binding 
    ptr->hello(); //Virtual Function

    return 0;
}

// * Virtual Functions are dynamic in nature.
// * Defined by the keyword "virtual" inseide a base 
//   class and are always declared with a base class
//   overridden in a child class
// * A Virtual Function is called during Runtime