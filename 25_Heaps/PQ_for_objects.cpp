#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Student { // "<" Overloading less than Operator.
    public : 
        string name;
        int marks;

        Student(string name, int marks) {
            this->name = name;
            this->marks = marks;
        }

        // For max Heap : 
        // bool operator < (const Student &obj) const {
        //     return this->marks < obj.marks;
        // }

        // For min Heap : 
        bool operator < (const Student &obj) const {
            return this->name > obj.name;
        }
};

int main() {
    priority_queue<Student> pq;

    pq.push(Student("aman", 85));
    pq.push(Student("bhumika", 95));
    pq.push(Student("chetan", 65));
    
    while(!pq.empty()) {
        cout << "Top : " << pq.top().name << " , " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}