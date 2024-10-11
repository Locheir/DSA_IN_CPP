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

class Mammal : public Animal {
    public :
        string bloodType;

        Mammal() {
            bloodType = "warm";
        }
};

class Dog : public Mammal {
    public :

        void tailWag() {
            cout << "Dog wags it's tail" << endl;
        }
};

int main() {
    Dog d1;

    d1.eat();
    d1.breathe();
    d1.tailWag();
    cout << d1.bloodType << endl;

    return 0;
}