#include <iostream>
using namespace std;

// Static objects will only get deleted when the main program ends.

class Example {
    public : 
        Example() {
            cout << "Constructor..\n";
        }

        ~Example() {
            cout << "Destructor..\n";
        }
};

int main() {
    int a = 0;
    if (a==0) {
        static Example eg1;
    }

    cout << "Code Ending..\n";
    
    return 0;
}