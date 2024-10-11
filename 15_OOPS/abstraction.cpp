#include <iostream>
using namespace std;

// Abstraction : 
// Hiding all unnecessary details & showing 
// only the important parts

// Abstraction using Abstarct Classes and Pure Virtual Functions.
// we mush have at least one pure virtual function in Abstract Class.

// * these are used to provide a base class from which other classes can be derived.
// * they cannot be instantiated and are meant to be inherited.
// * these are typically used to define an interface for derived class

class Shape {
    public :
        virtual void draw() = 0; // Pure Virtual Function
};

class Square : public Shape {
    public :
        void draw() {
            cout << "* * * *" << endl;
            cout << "*     *" << endl;
            cout << "*     *" << endl;
            cout << "* * * *" << endl;
        }
};

class Triangle : public Shape {
    public :
        void draw() {
            cout << "*" << endl;
            cout << "* *" << endl;
            cout << "*   *" << endl;
            cout << "* * * *" << endl;
        }
};

int main() {
    Square sq1;
    sq1.draw();

    Triangle t1;
    t1.draw();
    
    return 0;
}