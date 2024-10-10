#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

// classes : group of entities 
// object : entities in the real world

// classes : blueprint
// object : instance of a class

// classes : collection of attributes(properties) & functions(methods/member functions)


// Student in a college 
class Student {
    // Properties
    string name;
    float cgpa; 

    //Methods 
    void getPercentage() {
        cout << (cgpa*10) << "% \n";
    }
};


// User in Instagram : 
class User {
    int id;
    string username;
    string password;
    string bio;

    void deactivate() {
        cout << "deleting account \n";
    }

    void editBio(string newBio) {
        bio = newBio;
    }
};

int main() {

    Student s1;
    cout << sizeof(s1) <<endl;

    // new memory is assigned to this object.
    Student s2;
    cout << sizeof(s2) <<endl;

    return 0;
}