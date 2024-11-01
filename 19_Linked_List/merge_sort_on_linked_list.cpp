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
            } else {
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
        }
};

Node* merge(Node* left, Node* right) {
    LinkedList ll;

    while(left != NULL && right != NULL) {
        if (left->value < right->value) {
            ll.push_back(left->value);
            left = left->next;
        } else {
            ll.push_back(right->value);
            right = right->next;
        }
    }

    while (left != NULL) {
        ll.push_back(left->value);
        left = left->next;
    }

    while (right != NULL) {
        ll.push_back(right->value);
        right = right->next;
    }

    return ll.head;
};

Node* splitAtMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    return slow;
};

Node* mergeSort(Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMiddle(head);

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
};

int main() {
    LinkedList ll;
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.printList();

    ll.head = mergeSort(ll.head);
    ll.printList();
    return 0;
}