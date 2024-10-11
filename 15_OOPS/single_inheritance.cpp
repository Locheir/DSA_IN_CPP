#include <iostream>
using namespace std;

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
    f1.swim();
    f1.eat();
    f1.breathe();

    return 0;
}