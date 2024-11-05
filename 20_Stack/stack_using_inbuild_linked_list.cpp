#include <iostream>
#include <list>
using namespace std;

// Stack using LinkedList : 
template <class T>
class Stack {
    list<T> ll;

    public :
    
    void push(T value) {
        ll.push_front(value);
    }

    void pop() {
        ll.pop_front();
    }

    T top() {
        return ll.front();
    }

    bool isEmpty() {
        return ll.size() == 0;
    }
};

int main() {
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}