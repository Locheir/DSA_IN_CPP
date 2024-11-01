#include <iostream>
using namespace std;

class Node {
    public :
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            this->next = NULL;
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
            while(tmp_node != NULL) {
                cout << tmp_node->value;
                if (tmp_node->next != NULL) {
                    cout << "->";
                }
                tmp_node = tmp_node->next;
            }
            cout << endl;
        }

        bool detectCycle() {
            Node* slow = head;
            Node* fast = head;
            
            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow==fast) {
                    return true;
                }
            }

            return false;
        }
};

int main() {
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.printList();
    cout << ll.head->next << endl;
    ll.tail->next = ll.head->next;
    cout << ll.detectCycle();

    return 0;
}