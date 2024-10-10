#include <iostream>
using namespace std;

// Constructor : Special method involked automatically
// at time of object creation. Used for initialization.

class Car {
    string name;
    string color;

public :
    // Constructor without parameters || Non-parameterized Constructor
    Car() {
        cout << "Constructor without parameter is called" << endl;
    }

    // Constructor with parameters || Parameterized Constructor
    Car(string name, string color) {
        cout << "Constructor with parameter is called" << endl;
        this->name = name;
        // this->property  OR  *this.property
        this->color = color;
    }

    void start() {
        cout << "Car has started.." << endl;
    }

    void stop() {
        cout << "Car has stopped.." << endl;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }
};

int main() {
    Car c1; // Non-Parameterized Constructor
    Car c2("Maruti Suzuki", "White"); // Parameterized Constructor
    cout << c2.getName() << endl;
    cout << c2.getColor() << endl;

    return 0;
}