#include <iostream>
using namespace std;

class Student {
    string name;
    float cgpa;

public : 
    void setName(string nameVal) {
        name = nameVal;
    }

    void setCgpa(float cgpaVal) {
        cgpa = cgpaVal;
    }

    string getName() {
        return name;
    }

    float getCgpa() {
        return cgpa;
    }

    float getPercengtage() {
        return cgpa*10;
    }
};

int main() {
    Student s1;
    s1.setName("Mohit");
    s1.setCgpa(9.1);
    cout << s1.getCgpa() << endl;
    cout << s1.getName() << endl;
    cout << s1.getPercengtage() << endl;
    return 0;
}