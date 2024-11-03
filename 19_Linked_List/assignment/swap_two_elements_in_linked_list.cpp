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

Node* swap(int key1, int key2, Node* head) {
    Node *P = head;
    Node *prev = NULL;

    while (P != NULL && P->value != key1) {
        prev = P;
        P=P->next;
    }

    Node *PX = P;
    Node *prevX = prev;

    P = head;
    prev = NULL;

    while(P != NULL && P->value != key2) {
        prev = P;
        P = P->next;
    } 

    Node *PY = P;
    Node *prevY = prev;

    Node* temp;

    temp = PY->next;
    PY->next = PX->next;
    PX->next = temp;

    if (prevX == NULL) {
        head = PY;
        prevY->next = PX;
    }

    if (prevY == NULL) {
        head = PX;
        prevX->next = PY;
    }

    if (prevX != NULL && prevY != NULL) {
        prevX->next = PY;
        prevY->next = PX;
    }

    return head;
}

int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(7);
    ll.push_back(9);

    ll.printList();

    ll.head = swap(1, 7, ll.head);

    ll.printList();

    return 0;
}