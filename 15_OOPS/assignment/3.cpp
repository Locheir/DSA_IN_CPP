#include <iostream>
using namespace std;

class Person {
    protected :
        string name;
        int age;

    public :
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
};

class Student : public Person {
    private :
        int studentId;

    public :
        Student(int studentId, string name, int age) : Person(name, age) {
            this->studentId = studentId;
        }

        void displayStudentInfo() {
            cout << "*****STUDENT INFO******" << endl;
            cout << "Student Id : " << studentId << endl;
            cout << "Student Name : " << name << endl;
            cout << "Student Age : " << age << endl;
        }
};

int main() {
    Student s1(101,"mohit",21);
    s1.displayStudentInfo();

    return 0;
}