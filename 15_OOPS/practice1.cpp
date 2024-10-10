// Create a User Class with 
// Properties : id (private), username (public) & password (private)
// It's id should be initialized in a parameterized constructor
// It should have a Getter & Setter for password.
#include <iostream>
using namespace std;

class User {
    int id;
    string password;

public :
    string username;

    User(int id) {
        this->id = id;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

};

int main() {

    User u1(101);
    u1.username = "mohit";
    u1.setPassword("abcd");

    cout << "Username : " << u1.username << endl;
    cout << "Password : " << u1.getPassword() << endl;

    return 0;
}