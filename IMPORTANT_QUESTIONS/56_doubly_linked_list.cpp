#include <iostream>
using namespace std;

class Node {
    public :
        Node* prev;
        int value;
        Node* next;

        Node(int value) {
            prev = NULL;
            this->value = value;
            next = NULL;
        }
};

class DoublyLinkedList {
    public :
        Node* head;
        Node* tail;

        DoublyLinkedList() {
            head = tail = NULL;
        }

        void push_front(int value) {
            Node* new_node = new Node(value);

            if (head == NULL) {
                head = tail = new_node;
            } else {
                new_node->next = head;
                head->prev = new_node;

                head = new_node;
            }
        }
        
        void push_back(int value) {
            Node* new_node = new Node(value);

            if (head == NULL) {
                head = tail = NULL;
            } else {
                tail->next = new_node;
                new_node->prev = tail;

                tail = new_node;
            }
        }

        void pop_first() {
            if (head == NULL) {
                cout << "Linked List is Empty!" << endl;
                return;
            }

            if (head == tail) {
                Node* popped_node = head;
                head = tail = NULL;
                cout << "Removed Node : " << popped_node->value << endl;
                delete popped_node;
                return;
            }

            Node* popped_node = head;

            head = head->next;
            head->prev = NULL;
            popped_node->next = NULL;

            cout << "Removed Node : " << popped_node->value << endl;
            delete popped_node;
            
        }

        void pop_last() {
            if (head == NULL) {
                cout << "Linked List is Empty!" << endl;
                return;
            }

            if (head == tail) {
                Node* popped_node = head;
                head = tail = NULL;
                cout << "Removed Node : " << popped_node->value << endl;
                delete popped_node;
                return;
            }

            Node* popped_node = tail;
            tail = tail->prev;

            popped_node->prev = NULL;
            tail->next = NULL;

            cout << "Removed Node : " << popped_node->value << endl;
            delete popped_node;

        }

        void printList() {
            if (head == NULL) {
                cout << "Linked List is Empty!" << endl;
                return;
            }

            Node* tmp_node = head;

            while (tmp_node != NULL) {
                cout << tmp_node->value;
                if (tmp_node->next != NULL) {
                    cout << "->";
                }
                tmp_node = tmp_node->next;
            }

            cout << endl;
        }
};

int main() {
    DoublyLinkedList dll;

    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(5);

    dll.printList();

    dll.pop_first();
    dll.printList();

    dll.pop_last();
    dll.printList();

    return 0;
}