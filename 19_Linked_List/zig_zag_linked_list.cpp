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
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Node* zigZagList(Node* head) {
    Node* rightHead = splitAtMiddle(head);
    Node* right = reverse(rightHead);
    Node* left = head;
    Node* tail = NULL;

    while (left != NULL && right != NULL) {
        Node* left_next = left->next;
        Node* right_next = right->next;

        left->next = right;
        right->next = left_next;

        tail = right;

        left = left_next;
        right = right_next;
    }

    if (right != NULL) {
        tail->next = right;
    }
    
    return head;
}

int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.printList();

    ll.head = zigZagList(ll.head);
    ll.printList();

    return 0;
}