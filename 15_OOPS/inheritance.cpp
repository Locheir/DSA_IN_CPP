#include <iostream>
using namespace std;

// When properties & member functions of base 
// class are passed on to the derived class

class Animal {
public : 
    string color;

    void eat() {
        cout << "eats\n";
    }

    void breathe() {
        cout << "breathe\n";
    }
};

class Fish : public Animal{
public :
    int fins;

    void swim() {
        cout << "swim\n";
    }
};

int main() {

    Fish f1;

    f1.fins = 3;
    f1.swim();
    //the below functions are not possible here in 
    // private and protected mode of inheritance
    // f1.eat();
    // f1.breathe();

    return 0;
}