#include <iostream>
using namespace std;

// The memory that is created dynamically is not
// deallocated automatically by computer. Hence, 
// we have to define our own destructor.

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

        Car(Car &original) {
            name = original.name;
            color = original.color;
            mileage = new int;
            *mileage = *original.mileage;
        }

        ~Car() {
            cout << "Deleting object.\n";
            if(mileage != NULL) {
                delete mileage;
                mileage = NULL;
            }
        }
};

int main() {
    Car c1("BMW", "White");

    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << *c1.mileage << endl;

    return 0;
}