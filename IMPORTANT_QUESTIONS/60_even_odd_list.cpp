#include <iostream>
using namespace std;

class Node {
    public :
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = NULL;
        }
};

class LinkedList {
    public :
        Node* head;
        Node* tail;

        LinkedList() {
            head = tail = NULL;
        }

        void push_back(int value) {
            Node* new_node = new Node(value);
            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
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

Node* EvenOddLinkedList(Node* head) {
    Node* even = new Node(0);
    Node* odd; new Node(0);

    Node* tmp_node = head;
    Node* temp_even = even;
    Node* temp_odd = odd;

    while (tmp_node != NULL) {
        if(tmp_node->value%2 == 0) {
            Node* new_node = new Node(tmp_node->value);
            temp_even->next = new_node;
            temp_even = new_node;
        } else {
            Node* new_node = new Node(tmp_node->value);
            temp_odd->next = new_node;
            temp_odd = new_node;
        }
        tmp_node = tmp_node->next;
    }

    temp_even->next = odd->next;

    return even->next;
}

int main() {
    LinkedList ll;
    ll.push_back(8);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(6);

    ll.printList();

    ll.head = EvenOddLinkedList(ll.head);

    ll.printList();

    return 0;
}