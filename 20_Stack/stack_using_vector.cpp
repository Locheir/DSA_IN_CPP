#include <iostream>
#include <vector>
using namespace std;

class Stack {
    private :
        vector<int> vec;

    public : 
        void push(int value) {
            vec.push_back(value);
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << endl;
                return;
            }
            vec.pop_back();
        }

        int top() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << endl;
                return -1;
            }

            int lastIdx = vec.size() - 1;
            return vec[lastIdx];
        }

        bool isEmpty() {
            return vec.size() == 0;
        }
};

int main() {
    Stack s;
    
    s.push(3);
    s.push(2);
    s.push(1);

    for (int i=0; i<3; i++) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}