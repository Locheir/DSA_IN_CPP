#include <iostream>
using namespace std;

class Animal {
    public :
        void eat() {
            cout << "eats" << endl;
        }

        void breathe() {
            cout << "breathe" << endl;
        }
};

class Bird : public Animal {
    public :
        void fly() {
            cout << "Bird flies" << endl;
        }
};

class Fish : public Animal {
    public : 
        void swim() {
            cout << "Fish swims" << endl;
        }
};

class Human : public Animal {
    public :
        void walk() {
            cout << "Human Walks" << endl;
        }
};

int main() {
    Bird b1;
    b1.fly();
    b1.breathe();
    b1.eat();

    cout << endl;

    Fish f1;
    f1.swim();
    f1.breathe();
    f1.eat();

    cout << endl;

    Human h1;
    h1.walk();
    h1.breathe();
    h1.eat();

    return 0;
}