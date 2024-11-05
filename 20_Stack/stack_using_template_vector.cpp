#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Stack {
    private :
        vector<T> vec;
    public :
        void push(T value) {
            vec.push_back(value);
        }

        T top() {
            int topIndex = vec.size() - 1;
            return vec[topIndex];
        }

        void pop() {
            vec.pop_back();
        }

        bool isEmpty() {
            return vec.size() == 0;
        }
};

int main() {
    Stack<char> s;

    s.push('m');
    s.push('o');
    s.push('h');
    s.push('i');
    s.push('t');

    for(int i=0; i<5; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    Stack<int> s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);

    for(int i=0; i<3; i++) {
        cout << s2.top() << " ";
        s2.pop();
    }
    
    return 0;
}