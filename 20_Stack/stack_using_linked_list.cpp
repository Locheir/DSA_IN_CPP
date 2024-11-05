#include <iostream>
using namespace std;

template<class T>
class Node {
    public :
        T value;
        Node<T>* next;

        Node(T value) {
            this->value = value;
            next = NULL;
        }
};

template<class T>
class Stack {
    Node<T>* head;

    public : 
        void push(T value) {
            Node<T>* new_node = new Node<T>(value);
            if (head == NULL) {
                head = new_node;
            }
            new_node->next = head;
            head = new_node;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Linked List is Empty!" << endl;
                return;
            }
            Node<T> *popped_node = head;
            head = head->next;
            popped_node->next = NULL;
            delete popped_node;
        }

        T top() {
            return head->value;
        }

        bool isEmpty() {
            return head == NULL;
        }
};

int main() {
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    for (int i=0; i<3; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}