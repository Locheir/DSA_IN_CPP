#include <iostream>
using namespace std;

// Shallow Copy : copies reference to original array.
// Deep Copy : creates a brand new copy of the array.
// compiler generally creates a shallow copy for array
// so we have to define our own constructor for deep copy

class Car {
    public :
        string name;
        string color;
        int *mileage;

        Car(string name, string color) {
            this->name = name;
            this->color = color;
            mileage = new int;
            *mileage = 12;
        }

        // The below code is for Explicit Constructor that creates deep copy.

        // Car(Car &original) {
        //     name = original.name;
        //     color = original.color;
        //     mileage = new int;
        //     *mileage = *original.mileage;
        // }
};

int main() {
    Car c1("BMW", "White");
    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;
    *c2.mileage = 10;

    // After changing c2 value, c1's value also gets changed
    // This behaviour happens in the implicit constructor
    // This is basically shallow copy
    cout << *c1.mileage << endl;
    return 0;
}