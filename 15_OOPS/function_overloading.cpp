// Compile Time Polymorphism :
//  1. Function Overloading 

#include <iostream>
using namespace std;

class Print {
    public :

        void show(int num) {
            cout << "int :" << num << endl;
        }

        void show(string sent) {
            cout << "string : " << sent << endl;
        }
};

int main() {
    Print p1;
    p1.show(11);
    p1.show("Mohit");

    return 0;
}