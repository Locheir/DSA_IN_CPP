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

int size(Node* head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
};

Node* intersection(Node* headA, Node* headB) {
    int l1 = size(headA);
    int l2 = size(headB);
    int d;
    Node* ptr1;
    Node* ptr2;

    if (l1 > l2) {
        d = l1 - l2;
        ptr1 = headA;
        ptr2 = headB;
    } else {
        d = l2 - l1;
        ptr1 = headB;
        ptr2 = headA;
    }

    while (d>0) {
        ptr1 = ptr1->next;
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
};

int main() {

    LinkedList l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(0);
    l1.printList();

    LinkedList l2;
    l2.push_back(50);
    l2.push_back(17);
    l2.printList();
    l2.tail->next = l1.head->next->next;

    l1.printList();
    l2.printList();

    Node* ans = intersection(l1.head, l2.head);
    cout << ans->value << endl;
    return 0;
}