#include <iostream>
using namespace std;

template<class T>
class Stack {
    private :
        int size;
        T *arr;
        T top_el;

    public :
        Stack(int size) {
            top_el = -1;
            this->size = size;
            arr = new T[size];
        }

        void push(int x) {
            if (top_el == (size -1)) {
                return;
            }
            arr[++top_el] = x;
        }

        void pop() {
            if (isEmpty()) {
                return;
            }
            --top_el;
        }

        T top() {
            if (top_el == -1) {
                cout << "Stack is Empty";
                return NULL;
            }
            return arr[top_el];
        }

        bool isEmpty() {
            return top_el == -1;
        }
};

int main() {

    
    string example = "mohit";
    int n = 5;
    Stack<char> s(n);

    for (int i=0; i<n; i++) {
        s.push(example[i]);
    }

    for(int i=0; i<n; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}