#include <iostream>
using namespace std;

// Copy constructor is constructed automatically
// But we can also create a copy constructor explicitly

class Car {
    public :
        string name;
        string color;

        Car(string name, string color) {
            this->name = name;
            this->color = color;
        }

        Car(Car &original) {
            cout << "Copying original to new ...\n";
            name = original.name;
            color = original.color;
        }

};

int main() {
    Car c1("Maruti 800", "White");
    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;
    return 0;
}