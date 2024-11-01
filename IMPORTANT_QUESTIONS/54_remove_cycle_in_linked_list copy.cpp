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

        void removeCycle() {
            Node* slow = head;
            Node* fast = head;
            bool flag = false;

            while(fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    flag == true;
                    break;
                }
            }
            if (flag == false) {
                cout << "Cycle does'nt exist !" << endl;
                return;
            } 
            slow = head;

            if (slow == fast) {

                while(fast->next != slow) {
                    fast = fast->next;
                }

                fast->next = NULL;

            } else {
                Node* prev = NULL;

                while (slow != fast) {
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }

                prev->next = NULL;
            }

        }
    
};

int main() {
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.printList();

    ll.tail->next = ll.head;
    ll.removeCycle();
    ll.printList();

    return 0;
}