#include <iostream>
using namespace std;

// Access Modifiers : 
//  1. Public : data & methods accessible to everyone
//  2. Private : data & methods accessible only inside the class / friend functions
//  3. Protected : data & methods accessible inside class & to its derived class

class Student {
    private :
        string name;

    public :
        float cgpa;

        void getPercentage() {
            cout << (cgpa*10)<< "%" << endl;
        }
};

int main() {

    Student s1;
    // s1.name = "mohit";
    s1.cgpa = 9.0;
    cout << s1.cgpa <<endl;
    s1.getPercentage();

    return 0;
}